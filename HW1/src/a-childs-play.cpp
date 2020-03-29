#include <bits/stdc++.h>
#define maxw 20
#define maxh 10
using namespace std;
typedef pair<int,int> pii;

//  0
// 3 1
//  2
int stamp[maxw][maxh][4];

string G[maxh];

vector<pair<pii,int>> path;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

inline int next_dir(int row, int col, int dir, int w, int h) {
    for ( int i=0; i<4; ++i ) {
        int new_dir = (dir + i) % 4;
        int new_row = row + dx[new_dir];
        int new_col = col + dy[new_dir];
        // x-dir out of bound
        if ( new_row < 0 || h <= new_row )
            continue;
        // y-dir out of bound
        if ( new_col < 0 || w <= new_col )
            continue;
        // meet obstacle
        if ( G[new_row][new_col] == '#' )
            continue;
        return new_dir;
    }
}

inline pii walk(int row, int col, int dir, long long n, int w, int h) {
    while ( n >= 0 ) {
        if ( n == 0 )   return make_pair(row, col);
        if ( stamp[row][col][dir] > 0 ) {
            int cycle = path.size() - stamp[row][col][dir] + 1;
            return path[stamp[row][col][dir]-1 + n%cycle].first;
        }

        path.emplace_back(make_pair(make_pair(row, col), dir));
        stamp[row][col][dir] = path.size();

        dir = next_dir(row, col, dir, w, h);

        row += dx[dir];
        col += dy[dir];
        n--;
    }
}

int main()
{
    int w, h, st, ed;
    cin >> w >> h; cin.ignore();
    long long n;
    cin >> n; cin.ignore();
    for (int i = 0; i < h; i++) {
        getline(cin, G[i]);
        for ( int j=0; j<w; j++ )
            if ( G[i][j] == 'O' )
                st = i, ed = j;
    }

    pii ans = walk(st, ed, 0, n, w, h);
    cout << ans.second << ' ' << ans.first << '\n';
}