#include <iostream>

#include "Vector2f.h"

class Obstacle
{
private:
    Vector2f position;
    float rayon; // en mm

public:
    Obstacle();
    Obstacle(Vector2f position, float rayon);

    Vector2f getPosition() const;
	float getRayon() const;
};
