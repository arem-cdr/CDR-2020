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

vector<Vector2<int>> DijkstraPathfinding::generatePath(Vector2<int> startPos, Vector2<int> endPos)
{
    vector<Vector2<int>> returnVector;

    returnVector.push_back(startPos);

    return returnVector;
}

void DijkstraPathfinding::transformObstacleInWeight()
{
}

void DijkstraPathfinding::transformObstacleInWeightGradient()
{
}