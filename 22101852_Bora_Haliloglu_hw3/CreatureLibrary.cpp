//
// Created by bhll on 3/30/23.
//

#include "CreatureLibrary.hpp"
using namespace std;
void CreatureLibrary::fight(vector<Creatures*> &fighters) {
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

Food *CreatureLibrary::bestFoodFinder(vector<Food*> &foods) {
    Food* bestFood = nullptr;
    for (auto& food : foods) {
        if (bestFood == nullptr || food->getQuality() > bestFood->getQuality() ||
            (food->getQuality() == bestFood->getQuality() && food->getId() < bestFood->getId())) {
            bestFood = food;
        }
    }
    return bestFood;
}
double CreatureLibrary::calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

CreatureLibrary::CreatureLibrary(Creatures *arr):arr(arr){

}

void CreatureLibrary::gameEngine(vector<Food *> &foods, vector<Creatures *> &creatures) {
    for(auto& food: foods){
        Food* bestFoodptr = bestFoodFinder(foods);
        while(!bestFoodptr->isEaten()){
            for(auto& creature: creatures){
                if(isFighting(creature, creatures)){
                    fight(creatures);
                    continue;
                }
                bool isEaten = canEat(bestFoodptr, creature);
                if(isEaten){
                    break;
                }
                getCloser(creature, bestFoodptr);
            }
        }
    }
}

bool CreatureLibrary::isFighting(Creatures* &aCreature, vector<Creatures *> &allCreatures) {
    for (auto& attacker : allCreatures) {
        if (attacker->isDead()) continue;
        for (auto& defender : allCreatures) {
            if (defender->isDead() || defender->getId() <= attacker->getId()) continue;
            if (calculateDistance(attacker->getX(), attacker->getY(), defender->getX(), defender->getY()) <= 2 &&
                defender->getHealth() <= attacker->getHealth() && (defender == aCreature|| attacker == aCreature)) {
                return true;
            }
        }
    }
    return false;
}

bool CreatureLibrary::canEat(Food* &foodPtr, Creatures* &theCreature) {
    if(calculateDistance(theCreature->getX(), theCreature->getY(), foodPtr->getX(), foodPtr->getY()) < 1){
        foodPtr->setEaten(true);
        theCreature->setHealth(theCreature->getHealth() + foodPtr->getQuality());
        return true;
    }
    return false;
}

void CreatureLibrary::getCloser(Creatures* &Creature, Food* &bestFoodPtr) {
        int dx = static_cast<int>(bestFoodPtr->getX() - Creature->getX());
        int dy = static_cast<int>(bestFoodPtr->getY() - Creature->getY());
        double dist = calculateDistance(Creature->getX(), Creature->getY(), bestFoodPtr->getX(), bestFoodPtr->getY());
        int max_dist = (Creature->getHealth() > 10) ? static_cast<int>(Creature->getHealth() / 10) : 1;
        double scale = max_dist / dist;
        int new_x = static_cast<int>(Creature->getX()) + static_cast<int>(dx * scale);
        int new_y = static_cast<int>(Creature->getY()) + static_cast<int>(dy * scale);
        Creature->setX(new_x);
        Creature->setY(new_y);

}
