#pragma once

#include <iostream>

class Vector2{

    public:
        Vector2();
        Vector2(float x,float y);
        void setX(float x);
        void setY(float y);
        float getX();
        float getY();
        
        

    private:
        float x;
        float y;

        

	


    friend std::ostream& operator<< (std::ostream& flux, Vector2 const& v);

};
