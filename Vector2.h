#pragma once

#include <iostream>

template <typename T>
class Vector2
{

public:
    Vector2() : x(0), y(0) {}
    Vector2(T x, T y) : x(x), y(y) {}

    T getX() { return y; }
    T getY() { return x; }

private:
    T x;
    T y;

    friend std::ostream &operator<<(std::ostream &flux, Vector2 const &v)
    {
        std::cout << v.x << " " << v.y << std::endl;

        return flux;
    }
};
