#include "point.h"

Point::Point() {}


Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}


bool Point::operator!=(Point point){
    if(point.x != this->x && point.y!= this->y){
       return true;
    }
    return false;

}

bool Point::operator==(Point point){
    if(point.x == this->x && point.y == this->y){
       return true;
    }
    return false;

}


