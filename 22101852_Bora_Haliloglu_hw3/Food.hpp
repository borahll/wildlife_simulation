/**
* Author : Bora Haliloglu
* ID: 22101852
* Section : 2
* Homework : 3
* Description : description of your code
*/

#ifndef WILDLIFE_SIMULATION_FOOD_HPP
#define WILDLIFE_SIMULATION_FOOD_HPP


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
private:
    int id;
    double x,y;
    int quality;
    bool eaten;
public:
    int getSpawnTime() const;

    void setSpawnTime(int spawnTime);

private:
    int spawnTime;
public:
    bool isEaten() const;

    void setEaten(bool eaten);
};
struct compare_all{
    bool operator()(const Food* food1, const Food* Food2){
        return (food1->getSpawnTime() < Food2->getSpawnTime());
    }
};
struct compare_Quality{
    bool operator()(const Food* food1, const Food* Food2){
        return (food1->getQuality() < Food2->getQuality());
    }
};

#endif //WILDLIFE_SIMULATION_FOOD_HPP
