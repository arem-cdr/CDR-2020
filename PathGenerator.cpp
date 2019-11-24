#include "PathGenerator.h"

PathGenerator::PathGenerator()
{
    algoPathfinding = new DijkstraPathfinding();
}

PathGenerator::~PathGenerator()
{
    delete algoPathfinding;
    algoPathfinding = NULL;
}

vector<Vector2> PathGenerator::generatePath(Vector2 startPos, Vector2 endPos)
{
    this->generatedPath = this->algoPathfinding->generatePath(startPos, endPos);

    return this->generatedPath;
}

std::ostream &operator<<(std::ostream &flux, PathGenerator const &pathGenerator)
{
    for (int i = 0; i < pathGenerator.generatedPath.size(); i++)
    {
        std::cout << "Point " << i << " : " << pathGenerator.generatedPath[i] << endl;
    }

    return flux;
}
