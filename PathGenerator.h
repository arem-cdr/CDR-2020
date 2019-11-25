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

    vector<Vector2<int>> generatedPath;

public:
    PathGenerator();
    ~PathGenerator();

    vector<Vector2<int>> generatePath(Vector2<int> startPos, Vector2<int> endPos);

    friend std::ostream &operator<<(std::ostream &flux, PathGenerator const &pathGenerator);
};