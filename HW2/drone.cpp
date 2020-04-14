#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#define x first
#define y second
#define eb(a) emplace_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
inline int dist(pii a, pii b) {
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
inline int findZone(int Z, vector<pii> zone, pii loc) {
    for ( int i=0; i<Z; ++i ) {
        if ( dist(zone[i], loc) <= 10000 )
            return i;
    }
    return -1;
}
inline int roundDist(pii a, pii b) {
    return dist(a,b)/10000 + int(dist(a,b)%10000!=0);
}
inline void operation(int ID, int D, int Z, vector<pii> zone, vector<pii> drone, vector<pii> occupy, vector<pii> &goal, vector<vector<int>> zoneState) {
    
    vector<int> zoneMax(Z), zoneStay(Z);
    for ( int i=0; i<Z; ++i ) {
        for ( int j=0; j<zoneState[i].size(); ++j ) {
            if ( j == occupy[i].x && j == ID ) continue;
            zoneMax[i] = max(zoneMax[i], zoneState[i][j]);
        }
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> randZone(Z);
    
    for ( int i=0; i<Z; ++i )   randZone[i] = i;
    
    random_shuffle(randZone.begin(), randZone.end());
    
    for ( int _=0; _<Z; ++_ ) {
        int i = randZone[_];
        if ( occupy[i].x == ID )   continue;
        pq.push(mp(occupy[i].y+1, i)); // -zoneState[i][ID] // second condition should be random
    }
    
    set<int> idle;
    
    for ( int i=0; i<D; ++i ) {
        int zn = findZone(Z, zone, drone[i]);
        int gzn = findZone(Z, zone, goal[i]);
        if ( zn != -1 && occupy[zn].x == ID && zoneStay[zn] <= zoneMax[zn] ) {
            zoneStay[zn]++;
            goal[i] = drone[i];
            continue;
        }
        if ( (goal[i].x != drone[i].x || goal[i].y != drone[i].y) && gzn != -1 && zoneStay[gzn] <= zoneMax[zn] ) {
            zoneStay[gzn]++;
            continue;
        }
        idle.insert(i);
    }
    while ( !pq.empty() ) {
        pii temp = pq.top();
        priority_queue<pii, vector<pii>, greater<pii>> sorted;
        for ( auto i=idle.begin(); i!=idle.end(); i++ ) {
            sorted.push(mp(dist(zone[temp.y], drone[*i]), *i));
        }
        while ( temp.x-- && !sorted.empty() ) {
            pii dr = sorted.top();  sorted.pop();
            goal[dr.y] = zone[temp.y];
            idle.erase(dr.y);
        }
        pq.pop();
        if ( idle.empty() )   break;
    }
}
int main() {
    int P; // number of players in the game (2 to 4 players)
    int ID; // ID of your player (0, 1, 2, or 3)
    int D; // number of drones in each team (3 to 11)
    int Z; // number of zones on the map (4 to 8)
    cin >> P >> ID >> D >> Z;
    vector<pii> zone;
    for ( int i=0; i<Z; ++i ) {
        int X, Y;   cin >> X >> Y;
        zone.eb(mp(X, Y));
    }
    // game loop
    vector<pii> drone(D), goal(D);
    bool init = 1;
    while (1) {

        vector<pii> occupy;
        vector<vector<int>> zoneState(Z, vector<int>(P));

        for ( int i=0; i<Z; ++i ) {
            int TID;    cin >> TID;
            occupy.eb(mp(TID, 0));
        }
        for ( int i=0; i<P; ++i ) {
            for ( int j=0; j<D; ++j ) {
                int X, Y;   cin >> X >> Y;
                if ( i == ID ) {
                    drone[j] = mp(X, Y);
                    if ( init ) goal[j] = drone[j];
                }
                int zn = findZone(Z, zone, mp(X, Y));
                if ( zn != -1 && occupy[zn].x == i )    occupy[zn].y++;
                if ( zn != -1 ) zoneState[zn][i]++;
            }
        }

        operation(ID, D, Z, zone, drone, occupy, goal, zoneState);

        for ( pii i : goal )
            cout << i.x << ' ' << i.y << '\n';

        init = 0;
    }
}