/**
* Author : Bora Haliloglu
* ID: 22101852
* Section : 2
* Homework : 3
* Description : description of your code
*/

#ifndef WILDLIFE_SIMULATION_FOOD_HPP
#define WILDLIFE_SIMULATION_FOOD_HPP
#include <queue>
using namespace std;
struct compare_all;
class Food {
public:
    Food(int id, double x, double y, int quality, int spawnTime);
    int getId() const;
    void setId(int id);
    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);
    int getQuality() const;
    void setQuality(int quality);
    //void addToInGame(priority_queue<Food*, vector<Food*>, compare_all> allFoods, priority_queue<Food*, vector<Food*>, compare_all> &ingame, int time);
    bool isEaten() const;
    void setEaten(bool eaten);
    int getSpawnTime() const;
    void setSpawnTime(int spawnTime);
private:
    int id;
    double x,y;
    int quality;
    bool eaten;
    int spawnTime;
};
struct compare_all{
    bool operator()(const Food* food1, const Food* Food2){
        return (food1->getSpawnTime() > Food2->getSpawnTime());
    }
};
struct compare_Quality{
    bool operator()(const Food* food1, const Food* Food2){
        return (food1->getQuality() < Food2->getQuality());
    }
};

#endif //WILDLIFE_SIMULATION_FOOD_HPP
