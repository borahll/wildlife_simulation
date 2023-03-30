/**
* Author : Bora Haliloglu
* ID: 22101852
* Section : 2
* Homework : 3
* Description : description of your code
*/

#include "Food.hpp"

Food::Food(int id, double x, double y, int quality) : id(id), x(x), y(y), quality(quality), eaten(false){

}

int Food::getId() const {
    return id;
}

void Food::setId(int id) {
    Food::id = id;
}

double Food::getX() const {
    return x;
}

void Food::setX(double x) {
    Food::x = x;
}

double Food::getY() const {
    return y;
}

void Food::setY(double y) {
    Food::y = y;
}

int Food::getQuality() const {
    return quality;
}

void Food::setQuality(int quality) {
    Food::quality = quality;
}

bool Food::isEaten() const {
    return eaten;
}

void Food::setEaten(bool eaten) {
    Food::eaten = eaten;
}
