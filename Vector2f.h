#pragma once

#include <iostream>
#include <cmath>

class Vector2f
{

public:
    Vector2f() : x(0), y(0) {}
    Vector2f(float x, float y) : x(x), y(y) {}
    

    float getX() { return y; }
    float getY() { return x; }
    

private:
    float x;
    float y;
    
    friend std::ostream &operator<<(std::ostream &flux, Vector2f const &v)
    {
        std::cout << v.x << " " << v.y << std::endl;

        return flux;
    }
    friend bool operator== (Vector2f v1, Vector2f v2){
 
      return (v1.x == v2.x)&&(v1.y == v2.y);

    }

    /*friend void operator+= (Vector2 v1){
        x += v1.x;
        y += v1.y;
    }*/
     friend Vector2f operator+ (Vector2f v1,Vector2f v2){
        Vector2f copy(v1);
        copy.x += v2.x;
        copy.y += v2.y;
        return copy;
    }
    friend Vector2f operator* (Vector2f v1,Vector2f v2){
        Vector2f copy(v1);
        copy.x *= v2.x;
        copy.y *= v2.y;
        return copy;
    }
    friend Vector2f operator- (Vector2f v1,Vector2f v2){
        Vector2f copy(v1);
        copy.x -= v2.x;
        copy.y -= v2.y;
        return copy;
    }
    friend float dot (Vector2f v1,Vector2f v2){
        return v1.x*v2.x + v1.y*v2.y;
    }
    friend float distance (Vector2f v1,Vector2f v2){
        return sqrt(pow((v1.x-v2.x),2) + pow((v1.y-v2.y),2)) ;
    }
    
};
