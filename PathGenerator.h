#pragma once

#include <iostream>
#include <vector>

#include "Vector2.h"
#include "Pathfinding.h"
#include "DijkstraPathfinding.h"

using namespace std;

class PathGenerator
{
private:
    Pathfinding *algoPathfinding;

    vector<Vector2> generatedPath;

public:
    PathGenerator();
    ~PathGenerator();

    vector<Vector2> generatePath(Vector2 startPos, Vector2 endPos);

    friend std::ostream &operator<<(std::ostream &flux, PathGenerator const &pathGenerator);
};