#pragma once

#include <iostream>
#include "Vector2f.h"


class PointS
{

public:
    PointS() : x(0), y(0), z(0){}
    PointS(float x, float y, float z) : x(x), y(y), z(z) {}
    

    float getX() { return y; }
    float getY() { return x; }
    float getZ() { return z; }
    Vector2f toV2f() { Vector2f v(x,y); return v;}
    

private:
    float x;
    float y;
    float z;
    
    friend std::ostream &operator<<(std::ostream &flux, PointS const &v)
    {
        std::cout << v.x << " " << v.y << " " << v.z << std::endl;

        return flux;
    }
   

    
    
};
