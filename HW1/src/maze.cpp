#include "maze.h"

// check whether this location is walkable or not
bool Maze::isObstacle(pair<int,int> loc) const {
    if ( loc.first < 0 || height <= loc.first )
        return false;
    if ( loc.second < 0 || width <= loc.second )
        return false;
    if ( maze[loc.first][loc.second] == '#' )
        return false;
    return true;
}