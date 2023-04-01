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
#include "Food.hpp"
#include "Creatures.hpp"
#include <fstream>
#include <stack>
using namespace std;
void const checkTheInput(string const str);
vector<Creatures*> allCreatures;
priority_queue<Food*, vector<Food*>, compare_all> allFoods;
priority_queue<Food*, vector<Food*>, compare_Quality> ingameFood;
int main(){

    checkTheInput("input.txt");
    return 0;
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
            int result = stoi(num);
            q.push(result);
            entryCount++;
            if(begin2 <= begin1){
                /*
                 * Create the new creature and add to the queue
                 */
                //Creatures* aCreature = new Creatures();
                cout<<"A Creature is coming:"<<endl;
                double id = q.front();
                q.pop();
                double XCoordinate = q.front();
                q.pop();
                int YCoordinate = q.front();
                q.pop();
                int health = q.front();
                q.pop();
                Creatures* aCreature = new Creatures(id, health, XCoordinate, YCoordinate);
                allCreatures.push_back(aCreature);
            }
            else{
                cout<<"A Food is coming:"<<endl;
                double id = q.front();
                q.pop();
                double XCoordinate = q.front();
                q.pop();
                int YCoordinate = q.front();
                q.pop();
                int quality = q.front();
                q.pop();
                int spawnTime = q.front();
                q.pop();
                Food* aFood = new Food(id, XCoordinate, YCoordinate, quality, spawnTime);
                allFoods.push(aFood);
            }
        }
    }
}