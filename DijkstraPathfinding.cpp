#include "DijkstraPathfinding.h"

DijkstraPathfinding::DijkstraPathfinding()
{
    for (int i = 0; i < nbSubX; i++)
    {
        for (int j = 0; j < nbSubY; j++)
        {
            matrix[i][j] = 0.f;
        }
    }
}

void DijkstraPathfinding::updateObstacle(vector<Obstacle> obstacles)
{
}

vector<Vector2f> DijkstraPathfinding::generatePath(Vector2f startPos, Vector2f endPos)
{
    vector<Vector2f> returnVector;

    returnVector.push_back(startPos);

    return returnVector;
}

void DijkstraPathfinding::transformObstacleInWeight()
{
}

void DijkstraPathfinding::transformObstacleInWeightGradient()
{
}