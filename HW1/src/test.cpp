#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Maze {
public:
    Maze(int w, int h, vector<string> mz):width(w), height(h), maze(mz) {}
    bool isObstacle(pair<int,int> loc) const;
private:
    const int width, height;
    const vector<string> maze;
};
bool Maze::isObstacle(pair<int,int> loc) const {
    if ( loc.first < 0 || height <= loc.first )
        return false;
    if ( loc.second < 0 || width <= loc.second )
        return false;
    if ( maze[loc.first][loc.second] == '#' )
        return false;
    return true;
}

class Robot {
public:
    Robot(int width, int height, long long _step, pair<int,int> _start) {
        step = _step;
        location = _start;
        direction = 0;
    }
    pair<int,int> go(const Maze maze);
private:
    long long step;
    pair<int,int> location;
    vector<pair<int,int>> history;
    map<pair<int,int>,int> stamp[4];
    int direction;
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
};
pair<int,int> Robot::go(const Maze maze) {
    while ( step > 0 ) {
        if ( stamp[direction][make_pair(location.first, location.second)] > 0 ) {
            int cycle_length = history.size() - stamp[direction][make_pair(location.first, location.second)] + 1;
            return history[stamp[direction][make_pair(location.first, location.second)]-1 + step%cycle_length];
        }
        history.emplace_back(location);
        stamp[direction][make_pair(location.first, location.second)] = history.size();
        for ( int i=0; i<4; ++i ) {
            int new_direction = (direction + i) % 4;
            if ( maze.isObstacle(make_pair(location.first+dx[new_direction], location.second+dy[new_direction])) ) {
                direction = new_direction;
                location.first += dx[direction];
                location.second += dy[direction];
                break;
            }
        }
        step--;
    }
    return location;
}
int main() {

    // read input
    int w, h;
    long long n;
    cin >> w >> h >> n;
    vector<string> temp_maze(h);
    pair<int,int> st;
    for ( int i=0; i<h; ++i ) {
        cin >> temp_maze[i];
        for ( int j=0; j<w; ++j )
            if ( temp_maze[i][j] == 'O' )
                st = make_pair(i, j);
    }

    // initialize object with constructor
    Maze maze = Maze(w, h, temp_maze);
    Robot robot = Robot(w, h, n, st);

    // start moving & get terminal location
    pair<int,int> ans = robot.go(maze);
    cout << ans.second << ' ' << ans.first;

    return 0;
}
