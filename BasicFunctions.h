#pragma once

#include "Vector2f.h"
#include "Vector2i.h"

#include <math.h>

float dist(Vector2f v1, Vector2f v2)
{
	return sqrt(pow(v2.getX() - v1.getX(), 2) + pow(v2.getY() - v1.getY(), 2));
}

float dist(Vector2i v1, Vector2i v2)
{
	return sqrt(pow(v2.getX() - v1.getX(), 2) + pow(v2.getY() - v1.getY(), 2));
}