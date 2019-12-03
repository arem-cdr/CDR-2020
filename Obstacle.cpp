#include "Obstacle.h"

Obstacle::Obstacle() : rayon(0)
{
}

Obstacle::Obstacle(Vector2f position, float rayon) : position(position), rayon(rayon)
{
}

Vector2f Obstacle::getPosition() const
{
    return position;
}

float Obstacle::getRayon() const
{
	return rayon;
}
