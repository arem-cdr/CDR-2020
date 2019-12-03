#pragma once

#include <iostream>

#include "Pathfinding.h"

class DijkstraPathfinding : public Pathfinding
{
private:
    Vector2f matrix[nbSubX][nbSubY];

public:
    DijkstraPathfinding();

    virtual void updateObstacle(vector<Obstacle> obstacles);
    virtual vector<Vector2f> generatePath(Vector2f startPos, Vector2f endPos);

    void transformObstacleInWeight();
    void transformObstacleInWeightGradient();
};