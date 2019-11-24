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

vector<Vector2> DijkstraPathfinding::generatePath(Vector2 startPos, Vector2 endPos)
{
    vector<Vector2> returnVector;

    returnVector.push_back(startPos);

    return returnVector;
}

void DijkstraPathfinding::transformObstacleInWeight()
{
}

void DijkstraPathfinding::transformObstacleInWeightGradient()
{
}