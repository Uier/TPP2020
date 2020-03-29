#include "robot.h"
#include "maze.h"

#include <iostream>
#include <vector>
using namespace std;

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
    Robot robot = Robot(n, st);

    // start moving & get terminal location
    robot.printLocation(robot.go(maze));

    return 0;
}
