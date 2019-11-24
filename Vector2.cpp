#include "Vector2.h"

Vector2::Vector2()
{
    x = 0.f;
    y = 0.f;
}

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Vector2::getX()
{
    return this->x;
}

float Vector2::getY()
{
    return this->y;
}

std::ostream &operator<<(std::ostream &flux, Vector2 const &v)
{
    std::cout << v.x << " " << v.y << std::endl;

    return flux;
}