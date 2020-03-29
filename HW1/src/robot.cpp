#include "robot.h"
#include "maze.h"

// start moving until using up all the steps or in a loop.
pair<int,int> Robot::go(const Maze maze) {
    while ( step > 0 ) {
        // if I've visit this location & the direction I face are both same, indicating I'm in a loop.
        if ( stamp[direction][location] > 0 ) {
            // find the terminal location with mod.
            int cycle_length = history.size() - stamp[direction][location] + 1;
            return history[stamp[direction][location]-1 + step%cycle_length];
        }
        // push location into my history.
        history.emplace_back(location);
        // stamp stores index(+1) which the location & the direction at in history.
        stamp[direction][location] = history.size();
        // trying which direction can I move.
        for ( int i=0; i<4; ++i ) {
            int new_direction = (direction + i) % 4;
            if ( maze.isObstacle(make_pair(
                 location.first+dv[new_direction], location.second+dh[new_direction])) ) {
                direction = new_direction;
                location.first += dv[direction];
                location.second += dh[direction];
                break;
            }
        }
        step--;
    }
    return location;
}