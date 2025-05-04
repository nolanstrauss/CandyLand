// CSCI 1300 Fall 2023
// Author: Nolan Strauss
// TA: Mahi
// Question 5
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;
struct Candy
{
    string name;
    string description;
    double price;
    string candy_type;
    int effect_value;
    string effect_type;
};

class Player
{
    private:
        const static int _MAX_CANDY_AMOUNT = 9;
        int _stamina;
        double _gold;
        string _effect;
        Candy _inventory[_MAX_CANDY_AMOUNT];
        int _candy_amount;
        string _name;
        bool skip;
        bool hasRobberRepel;
        
    
    public:
        Player();
        Player(string, int, double, Candy[], const int);

        int getCandyAmount();

        void setStamina(int);
        int getStamina();

        void setGold(double);
        double getGold();

        void setName(string);
        string getName();

        void printInventory();

        Candy findCandy(string);
        bool addCandy(Candy);
        bool removeCandy(const string&);
        void substituteCandy(Candy,Candy);

        void setSkip(bool);
        bool isSkip(int);
        bool rockPaperScissors();
      
    
};
#endif

