#ifndef ROBOT__
#define ROBOT__

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Maze;

class Robot {
public:
    Robot(long long _step, pair<int,int> _start) {
        step = _step;
        location = _start;
        direction = 0;
    }
    pair<int,int> go(const Maze maze);
    void printLocation(pair<int,int> loc) { cout << loc.second << ' ' << loc.first << '\n'; }
private:
    // 0: up, 1: right, 2: down, 3: left
    int direction;
    const int dv[4] = {-1, 0, 1, 0}; // vertical delta
    const int dh[4] = {0, 1, 0, -1}; // horizontal delta
    long long step;
    pair<int,int> location;
    vector<pair<int,int>> history;
    map<pair<int,int>,int> stamp[4];
};

#endif