#include <iostream>
using namespace std;
#ifndef DECK_H
#define DECK_H

class Card{
    private:
        string color;
        string type;
    public:
        Card();
        bool isDouble(Card);
        Card drawCard();

        string getColor();
        string getType();
        
};
#endif