#include <iostream>

#include "Vector2.h"

class Obstacle
{
private:
    Vector2 position;
    int rayon; // en mm

public:
    Obstacle();
    Obstacle(Vector2 position, int rayon);

    Vector2 getPosition();
};
