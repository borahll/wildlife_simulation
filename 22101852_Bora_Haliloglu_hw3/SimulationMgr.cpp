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
/*#include "Food.hpp"
#include "Creatures.hpp"*/
#include <string>
#include <fstream>
#include <stack>
using namespace std;
void const checkTheInput(string const str);
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
            int result = stoi(num);
            q.push(result);
            entryCount++;
            if(entryCount == 4){
                cout<<"A Creature is coming:"<<endl;
                cout<<"X coor: "<<q.front()<<endl;
                q.pop();
                cout<<"Y coor: "<<q.front()<<endl;
                q.pop();
                cout<<"ID: "<<q.front()<<endl;
                q.pop();
                cout<<"Quality: "<<q.front()<<endl;
                q.pop();
            }
            else if(entryCount == 5){
                cout<<"A Food is coming:"<<endl;
                cout<<"X coor: "<<q.front()<<endl;
                q.pop();
                cout<<"Y coor: "<<q.front()<<endl;
                q.pop();
                cout<<"ID: "<<q.front()<<endl;
                q.pop();
                cout<<"Quality: "<<q.front()<<endl;
                q.pop();
                cout<<"Spawn time: "<<q.front()<<endl;
                q.pop();
            }
        }
    }
}