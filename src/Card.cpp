#include "Card.h"
#include <cstdlib>
#include <ctime> 
#include <iostream>

Card::Card(){
    color = "";
    type = "";
}
Card Card::drawCard() {
    srand((unsigned)time(NULL));
    int rand_num = rand() % 100;
    const int COLOR_COUNT = 3;
    const string COLORS[COLOR_COUNT] = {"Magenta", "Green", "Blue"};
    Card card;
    
    card.color = COLORS[static_cast<int>(rand()) % 3];
    if (rand_num > 90){
        card.type = "double";
    }
    else{
        card.type = "normal";
    }
    return card;
}
bool Card::isDouble(Card card){
    if (card.type == "normal"){
        return false;
    }
    return true;
}
string Card::getColor(){
    return color;
}
string Card::getType(){
    return type;
}