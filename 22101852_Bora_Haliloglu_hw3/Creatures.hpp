/**
* Author : Bora Haliloglu
* ID: 22101852
* Section : 2
* Homework : 3
* Description : description of your code
*/

#ifndef WILDLIFE_SIMULATION_CREATURES_HPP
#define WILDLIFE_SIMULATION_CREATURES_HPP
#include <vector>
#include "Food.hpp"
class Creatures {
public:
    Creatures(int id, double health, double x, double y);
    int getId() const;
    void setId(int id);
    double getHealth() const;
    void setHealth(double health);
    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);
    bool isDead() const;
    void setDead(bool dead);
private:
    int id;
    double health;
    double x,y;
    bool dead;
};


#endif //WILDLIFE_SIMULATION_CREATURES_HPP
