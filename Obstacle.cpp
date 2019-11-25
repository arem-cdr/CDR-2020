#include "Obstacle.h"

Obstacle::Obstacle() : rayon(0)
{
}

Obstacle::Obstacle(Vector2<int> position, int rayon) : position(position), rayon(rayon)
{
}

Vector2<int> Obstacle::getPosition()
{
    return this->position;
}