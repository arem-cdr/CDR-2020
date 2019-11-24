#pragma once

#include <iostream>

#include "Pathfinding.h"

class DijkstraPathfinding : public Pathfinding
{
private:
    float matrix[nbSubX][nbSubY];

public:
    DijkstraPathfinding();

    virtual void updateObstacle(vector<Obstacle> obstacles);
    virtual vector<Vector2> generatePath(Vector2 startPos, Vector2 endPos);

    void transformObstacleInWeight();
    void transformObstacleInWeightGradient();
};