/**
* Author : Bora Haliloglu
* ID: 22101852
* Section : 2
* Homework : 3
* Description : main() method containing the input, any pre-processing including
*data structure setups, game loop and output parts
*/
#include <iostream>
#include <string>
#include <queue>
#include "CreatureLibrary.hpp"
#include <fstream>
#include <stack>
#include <iomanip>
using namespace std;

void const checkTheInput(string const str);
void gameLoop(int time);
void addToInGame(priority_queue<Food*, vector<Food*>, compare_all> allFoods, priority_queue<Food*, vector<Food*>, compare_Quality>& ingame, int time);
bool checkIfAllEaten();
void print();
CreatureLibrary c;
int main() {
    setprecision(3);
    checkTheInput("input.txt");
    int time = 0;
    while (!checkIfAllEaten()){
        gameLoop(time);
        time++;
    }
    return 0;
}
bool checkIfAllEaten(){
    priority_queue<Food*, vector<Food*>, compare_all> all;
    all = c.allFoods;
    while(!all.empty()){
        if(!all.top()->isEaten()){
            return false;
        }
        all.pop();
    }
    return true;
}
void gameLoop(int time){
        addToInGame(c.allFoods, c.ingameFood, time);
        priority_queue<Food*, vector<Food*>, compare_Quality> temp;
        vector<Food*> allFood;
        temp = c.ingameFood;
        while(!temp.empty()){
            allFood.push_back(temp.top());
            temp.pop();
        }
        c.gameEngine(allFood, c.allCreatures);
}
void const checkTheInput( string const str){
    string inFile = str;
    int begin1 = 0, begin2 = 0;
    int entryCount = 0;
    ifstream infile;
    infile.open(inFile);
    if(!infile){
       cout << "Input file " << inFile << " does not exist" << endl;
    }
    else{
        infile >> begin1;
        while(infile.eof() == false){
            queue<double> q;
            string num = "";
            string temp = "";
            entryCount = 0;
            infile>>temp;
            for(int i = 0; i< static_cast<int>(temp.length()); i++){
                char c = temp[i];
                if(c != ','){
                    num.push_back(c);
                    continue;
                }
                else {
                    double result = stod(num);
                    q.push(result);
                    entryCount++;
                    num = "";
                }
            }
            begin2++;
            double result = stod(num);
            q.push(result);
            entryCount++;
            if(begin2 <= begin1){
                /*
                 * Create the new creature and add to the queue
                 */
                //Creatures* aCreature = new Creatures();
                double id = q.front();
                q.pop();
                double XCoordinate = q.front();
                q.pop();
                double YCoordinate = q.front();
                q.pop();
                double health = q.front();
                q.pop();
                Creatures* aCreature = new Creatures(id, health, XCoordinate, YCoordinate);
                c.allCreatures.push_back(aCreature);
            }
            else{
                double id = q.front();
                q.pop();
                double XCoordinate = q.front();
                q.pop();
                double YCoordinate = q.front();
                q.pop();
                double quality = q.front();
                q.pop();
                double spawnTime = q.front();
                q.pop();
                Food* aFood = new Food(id, XCoordinate, YCoordinate, quality, spawnTime);
                c.allFoods.push(aFood); // all foods
            }
        }
    }
}
void addToInGame(priority_queue<Food*, vector<Food*>, compare_all> allFoods, priority_queue<Food*, vector<Food*>, compare_Quality>& ingame, int time){
    while(!ingame.empty()){
        ingame.pop();
    }
    while(!allFoods.empty()){
        if(allFoods.top()->isEaten()){
            allFoods.pop();
            continue;
        }
        else{
            if(allFoods.top()->getSpawnTime() <= time){
                ingame.push(allFoods.top());
                allFoods.pop();
                continue;
            }
            allFoods.pop();
        }
    }
}
