#include <iostream>

#include "Vector2.h"

class Obstacle
{
private:
    Vector2<int> position;
    int rayon; // en mm

public:
    Obstacle();
    Obstacle(Vector2<int> position, int rayon);

    Vector2<int> getPosition();
};
