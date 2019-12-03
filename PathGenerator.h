#pragma once

#include <iostream>
#include <vector>

#include "Vector2f.h"
#include "Pathfinding.h"
#include "DijkstraPathfinding.h"
#include "AStarPathfinding.h"

using namespace std;

class PathGenerator
{
private:
    Pathfinding *algoPathfinding;

    vector<Vector2f> generatedPath;

public:
    PathGenerator();
    ~PathGenerator();

    vector<Vector2f> generatePath(Vector2f startPos, Vector2f endPos);

    friend std::ostream &operator<<(std::ostream &flux, PathGenerator const &pathGenerator);
};