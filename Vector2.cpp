#include "Vector2.h"

Vector2::Vector2(){
    x = 0.f;
    y = 0.f;
}

Vector2::Vector2(float x, float y){
    this-> x = x;
    this-> y = y;
}


std::ostream& operator<< (std::ostream& flux, Vector2 const& v) {
    std::cout << v.x << " "<< v.y<<std::endl;

    return flux;
}

float Vector2::getX() {
    return this->x;
}
void Vector2::setX(float x) {
    this->x = x;
}
float Vector2::getY() {
    return this->y;
}
void Vector2::setY(float y) {
    this->y = y;
}
Vector2 sum(Vector2 v1,Vector2 v2){
    Vector2 g(v1.getX()+v2.getX(),v1.getY()+v2.getY());
    return g;
}