#include <iostream>

#include "Vector2f.h"

class Obstacle
{
private:
    Vector2f position;
    int rayon; // en mm

public:
    Obstacle();
    Obstacle(Vector2f position, int rayon);

    Vector2f getPosition();
};
