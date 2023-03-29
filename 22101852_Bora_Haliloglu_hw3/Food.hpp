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
    Food(int id, double x, double y, int quality);
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
};


#endif //WILDLIFE_SIMULATION_FOOD_HPP
