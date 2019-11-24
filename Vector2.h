#include <iostream>

class Vector2{

    public:
        Vector2();
        Vector2(float x,float y);
        

    private:
        float x ;
        float y ;

    friend std::ostream& operator<< (std::ostream& flux, Vector2 const& v);

};
