#include "Vector2.h"

Vector2::Vector2(){
    x = .0f;
    y = .0f;


}
Vector2::Vector2(float x, float y){
    this-> x =x;
    this->y = y;
}
std::ostream& operator<< (std::ostream& flux, Vector2 const& v) {
    std::cout << v.x << " "<< v.y<<std::endl;
}

