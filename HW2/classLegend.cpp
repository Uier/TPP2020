#include <bits/stdc++.h>
#define eb(x) emplace_back(x)
using namespace std;

struct pos {
    int x, y;
    bool operator == (const pos &a) const { return (x == a.x && y == a.y); }
    int dist(const pos &a) const { return (x-a.x)*(x-a.x)+(y-a.y)*(y-a.y); }
};

class Zone {
public:
    Zone(int _id, int P) {
        cin >> loc.x >> loc.y;
        id = _id;
        occupier = -1;
        state.assign(P, 0);
        requiredDrone = dispatch = 0;
    }
    pos loc;
    int id, occupier, requiredDrone, dispatch;
    vector<int> state;
    pos Land(pos drone) {
        int dx = drone.x - loc.x, dy = drone.y - loc.y;
        if ( dx == 0 )  return (dy > 0 ? pos{loc.x, loc.y+100} : pos{loc.x, loc.y-100});
        if ( dy == 0 )  return (dx > 0 ? pos{loc.x+100, loc.y} : pos{loc.x-100, loc.y});
        if ( dy/dx > 0 )    return (dy > 0 ? pos{loc.x+70, loc.y+70} : pos{loc.x-70, loc.y-70});
        return (dy > 0 ? pos{loc.x-70, loc.y+70} : pos{loc.x+70, loc.y-70});
    }
};

class Drone {
public:
    Drone(int _id) { 
        cin >> loc.x >> loc.y;
        id = _id; 
    }
    pos loc, goal;
    int id, goalZone;
    void Print() { cout << goal.x << ' ' << goal.y << '\n'; }
    int FindZone(int Z, vector<Zone> zone) {
        for ( int i=0; i<Z; ++i )
            if ( loc.dist(zone[i].loc) <= 10000 )
                return i;
        return -1;
    }
};

inline void FirstAttack(int D, vector<Drone> &drone, int Z, vector<Zone> &zone) {
    for ( int i=0; i<D; ++i ) {
        int mn = 0;
        for ( int j=1; j<Z; ++j )
            if ( drone[i].loc.dist(zone[j].loc) < drone[i].loc.dist(zone[mn].loc) )
                mn = j;
        zone[mn].dispatch++;
        drone[i].goalZone = mn;
        drone[i].goal = zone[mn].Land(drone[i].loc);
    }
}

inline void Attack(int ID, int D, vector<Drone> &drone, int Z, vector<Zone> &zone) {
    // Find required drones to occupy that zone
    vector<pair<int,pair<int,int>>> attackZone;
    for ( int i=0; i<Z; ++i ) {
        zone[i].requiredDrone = 0;
        for ( int j=0; j<zone[i].state.size(); ++j ) {
            if ( j == ID && zone[i].occupier == ID )    continue;
            if ( zone[i].occupier == ID )
                zone[i].requiredDrone = max(zone[i].requiredDrone, max(1, zone[i].state[j]));
            else
                zone[i].requiredDrone = max(zone[i].requiredDrone, zone[i].state[j]+1);
        }
        if ( zone[i].dispatch > 0 ) {
            if ( zone[i].requiredDrone > zone[i].dispatch+zone[i].state[ID] ) {
                attackZone.eb(make_pair(zone[i].requiredDrone-zone[i].dispatch-zone[i].state[ID], make_pair(rand(), i)));
            }
        } else {
            attackZone.eb(make_pair(zone[i].requiredDrone, make_pair(rand(), i)));
        }
    }
    vector<int> stayZone(Z, 0);
    set<int> idle;
    // Find idling drones
    cerr << "required!!!~~~~~~\n";
    for ( int i=0; i<Z; ++i )   cerr << zone[i].requiredDrone << '\n';
    cerr << "dispatching~~~~~~\n";
    for ( int i=0; i<Z; ++i )   cerr << zone[i].dispatch << '\n';
    for ( int i=0; i<D; ++i ) {
        cerr << "i,gz: " << i << ' ' << drone[i].goalZone << '\n';
        int zn = drone[i].FindZone(Z, zone);
        // cerr << zn << '\n';
        if ( zn == -1 || drone[i].goalZone != -1 ) { // idling or flying
            cerr << "case1\n";
            if ( drone[i].goalZone == -1 ) {
                idle.insert(i);
            } else {
                int goalzn = drone[i].goalZone;
                cerr << zone[goalzn].state[ID] << ' ' << zone[goalzn].dispatch << ' ' << zone[goalzn].requiredDrone << '\n';
                if ( zone[goalzn].state[ID]+zone[goalzn].dispatch > zone[goalzn].requiredDrone ) {
                    zone[goalzn].dispatch--;
                    idle.insert(i);
                }
            }
        } else { // static
            cerr << "case2\n";
            if ( zone[zn].dispatch > 0 )    continue;
            idle.insert(i);
        }
    }
    cerr << "=============\n";
    cerr << "num of idle: " << idle.size() << '\n';
    for ( auto i=idle.begin(); i!=idle.end(); ++i ) cerr << "idle: " << *i << '\n';
    cerr << "=============\n";

    sort(attackZone.begin(), attackZone.end());
    
    cerr << "num of atzn: " << attackZone.size() << '\n';
    
    for ( auto i : attackZone ) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> near;
        for ( auto j=idle.begin(); j!=idle.end(); ++j )
            near.push(make_pair(drone[*j].loc.dist(zone[i.second.second].loc), *j));
        
        cerr << "num of near: " << near.size() << '\n';
        
        int req = i.first;
        
        cerr << "i: " << i.first << ' ' << i.second.first << ' ' << i.second.second << '\n';
        
        while ( near.size() >= req && req && !near.empty() ) {
            auto x = near.top();    near.pop();
            drone[x.second].goalZone = i.second.second;
            drone[x.second].goal = zone[i.second.second].Land(drone[x.second].loc);
            idle.erase(x.second);
            req--;
        }
        zone[i.second.second].dispatch += i.first - req;
        if ( near.empty() ) break;
    }
    for ( auto i=idle.begin(); i!=idle.end(); ++i ) drone[*i].goalZone = -1;
}

int main() {
    srand(time(NULL));

    int P; // number of players in the game (2 to 4 players)
    int ID; // ID of your player (0, 1, 2, or 3)
    int D; // number of drones in each team (3 to 11)
    int Z; // number of zones on the map (4 to 8)

    cin >> P >> ID >> D >> Z;
    
    // initialize zone
    vector<Zone> zone;
    for ( int i=0; i<Z; ++i ) {
        zone.eb( Zone(i, P) );
        cerr << "i, zn: " << i << ' ' << zone[i].loc.x << ' ' << zone[i].loc.y << '\n';
    }

    // initialize zone;
    vector<vector<Drone>> drone(P);
    for ( int i=0; i<Z; ++i )   cin >> zone[i].occupier;
    for ( int i=0; i<P; ++i )
        for ( int j=0; j<D; ++j )
            drone[i].eb( Drone(j) );

    FirstAttack(D, drone[ID], Z, zone);
    for ( int i=0; i<D; ++i )   drone[ID][i].Print();

    while ( true ) {

        for ( int i=0; i<Z; ++i ) {
            cin >> zone[i].occupier;
            for ( int j=0; j<P; ++j )   zone[i].state[j] = 0;
        }

        for ( int i=0; i<P; ++i ) {
            for ( int j=0; j<D; ++j ) {
                cin >> drone[i][j].loc.x >> drone[i][j].loc.y;
                int zn = drone[i][j].FindZone(Z, zone);
                if ( zn != -1 ) {
                    zone[zn].state[i]++;
                    if ( i == ID && drone[i][j].goalZone == zn ) {
                        zone[zn].dispatch--;
                        drone[i][j].goalZone = -1;
                    }
                }
            }
        }

        Attack(ID, D, drone[ID], Z, zone);
        for ( int i=0; i<D; ++i )   drone[ID][i].Print();

    }
    return 0;
}