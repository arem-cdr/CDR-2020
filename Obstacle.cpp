#include "Obstacle.h"

Obstacle::Obstacle() : position(0.f, 0.f), rayon(0)
{
}

Obstacle::Obstacle(Vector2 position, int rayon) : position(position), rayon(rayon)
{
}

Vector2 Obstacle::getPosition()
{
    return this->position;
}