#pragma once

#include <iostream>

#include "Pathfinding.h"

class AStarPathfinding : public Pathfinding
{
private:
    float matrix[nbSubX][nbSubY];

    //Vector2<int> mmToIndMatrix(Vector2<int> mm);
    //Vector2<int> indMatrixToMm(Vector2<int> indMatrix);

public:
    AStarPathfinding(float a);

    virtual void updateObstacle(vector<Obstacle> obstacles);
    virtual vector<Vector2<int>> generatePath(Vector2<int> startPos, Vector2<int> endPos);
};