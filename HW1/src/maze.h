#ifndef MAZE__
#define MAZE__

#include <vector>
#include <string>
using namespace std;

class Maze {
public:
    Maze(int w, int h, vector<string> mz):width(w), height(h), maze(mz) {}
    bool isObstacle(pair<int,int> loc) const;
private:
    const int width, height;
    const vector<string> maze;
};

#endif