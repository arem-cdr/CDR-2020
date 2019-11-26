#pragma once

#include <iostream>
#include <vector>
#include "Vector2i.h"
#include "Vector2f.h"
#include "Obstacle.h"

using namespace std;

const int nbSubX = 75; // dim des matrices utilisees dans les classes filles de pathfinding
const int nbSubY = 50;

const int sizeX = 3000; // dim du terrain
const int sizeY = 2000;

class Pathfinding
{
private:
public:
    Pathfinding();

    virtual void updateObstacle(vector<Obstacle> obstacles) = 0; // go checker le polymorphisme et les classes abstraites sur openclassroom pour comprendre ces lignes
    virtual vector<Vector2f> generatePath(Vector2f startPos, Vector2f endPos) = 0;
};
