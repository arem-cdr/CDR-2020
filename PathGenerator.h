#pragma once

#include "Vector2.h"

#include <vector>

using namespace std;

const int nbSubX = 300; 
const int nbSubY = 200;

class PathGenerator
{
private:

    const int sizeX; // dim du terrain
    const int sizeY;

    float matrix[nbSubX][nbSubY];

    vector<Vector2> generatedPath;

public:
    PathGenerator();

    void transformObstacleInWeight();
    void transformObstacleInWeightGradient();

    vector<Vector2> dijkstra();

    vector<Vector2> AStar();
    
};