/**
* Author : Bora Haliloglu & ALY
* ID: 22101852
* Section : 2
* Homework : 3
* Description : description of your code
*/
/*
 * TODO:
 * */
#include "Creatures.hpp"
#include <iostream>
#include <cmath>
using namespace std;
Creatures::Creatures(int id, double health, double x, double y): id(id), health(health), x(x), y(y){

}

int Creatures::getId() const {
    return id;
}

void Creatures::setId(int id) {
    Creatures::id = id;
}

double Creatures::getHealth() const {
    return health;
}

void Creatures::setHealth(double health) {
    Creatures::health = health;
}

double Creatures::getX() const {
    return x;
}

void Creatures::setX(double x) {
    Creatures::x = x;
}

double Creatures::getY() const {
    return y;
}

void Creatures::setY(double y) {
    Creatures::y = y;
}

bool Creatures::isDead() const {
    return dead;
}

void Creatures::setDead(bool dead) {
    Creatures::dead = dead;
}




