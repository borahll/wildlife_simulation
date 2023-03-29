/**
* Author : Bora Haliloglu
* ID: 22101852
* Section : 2
* Homework : 3
* Description : description of your code
*/

#include "Creatures.hpp"
#include <iostream>
#include <cmath>
using namespace std;
Creatures::Creatures(int id, double health, double x, double y) {

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

double Creatures::calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

void Creatures::fight(vector<Creatures*> &fighters) {
    for (auto& attacker : fighters) {
        if (attacker->isDead()) continue;
        for (auto& defender : fighters) {
            if (defender->isDead() || defender->getId() <= attacker->getId()) continue;
            if (calculateDistance(attacker->getX(), attacker->getY(), defender->getX(), defender->getY()) <= 2 &&
                defender->getHealth() <= attacker->getHealth()) {
                defender->setDead(true);
            }
        }
    }
}

Food *Creatures::bestFoodFinder(vector<Food*> &foods) {
    Food* bestFood = nullptr;
    for (auto& food : foods) {
        if (bestFood == nullptr || food->getQuality() > bestFood->getQuality() ||
            (food->getQuality() == bestFood->getQuality() && food->getId() < bestFood->getId())) {
            bestFood = food;
        }
    }
    return bestFood;
}
