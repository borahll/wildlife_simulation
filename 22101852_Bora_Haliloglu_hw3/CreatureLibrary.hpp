//
// Created by bhll on 3/30/23.
//

#ifndef WILDLIFE_SIMULATION_CREATURELIBRARY_HPP
#define WILDLIFE_SIMULATION_CREATURELIBRARY_HPP

#include "Creatures.hpp"
#include <iostream>
#include <cmath>
#include <vector>
//TODO: printCreature
using namespace std;
class CreatureLibrary {
public:
    CreatureLibrary(Creatures* arr);
    int len;
    Creatures* arr;//The array of Creatures that will be proccessed
    void fight(vector<Creatures*> &fighters);
    Food* bestFoodFinder(vector<Food*> &foods);
    double calculateDistance(double x1, double y1, double x2, double y2);
    void gameEngine(vector<Food*>& foods, vector<Creatures*>& creatures);
    bool isFighting(Creatures* aCreature, vector<Creatures*> allCreatures);
    bool canEat(Food* foodPtr, Creatures* theCreature);
    void getCloser(Creatures* allCreatures, Food* bestFoodPtr);
};


#endif //WILDLIFE_SIMULATION_CREATURELIBRARY_HPP
