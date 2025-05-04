#include <iostream>
#include <cctype> 
#include <algorithm>
#include "Player.h"

using namespace std;

const int Player::_MAX_CANDY_AMOUNT;

Player::Player(){
    _stamina = 0;
    _gold = 0;
    _candy_amount = 0;
    _name = "";
    for(int i = 0; i < _MAX_CANDY_AMOUNT; i++){
        _inventory[i].name = "";
        _inventory[i].description = "";
        _inventory[i].price = 0.0;
        _inventory[i].candy_type = "";
        _inventory[i].effect_type = "";
        _inventory[i].effect_value = 0;

    }
    skip = false;
    hasRobberRepel = false;
}
Player::Player(string name, int stamina, double gold, Candy candy_array[], const int CANDY_ARR_SIZE){
    _candy_amount = 0;
    _stamina = stamina;
    _gold = gold;
    for (int i = 0; i < min(CANDY_ARR_SIZE, _MAX_CANDY_AMOUNT); i++){
        _inventory[i] = candy_array[i];
        if(candy_array[i].name != "" && candy_array[i].description != "" && candy_array[i].price != 0 && candy_array[i].candy_type != "") {
            _candy_amount++;
        }
    }
    _name = name;
    skip = false;
}
int Player::getCandyAmount(){
    return _candy_amount;
}
void Player::setStamina(int stamina){
    _stamina = stamina;
}
int Player::getStamina(){
    return _stamina;
}
void Player::setGold(double gold){
    _gold = gold;
}
double Player::getGold(){
    return _gold;

 }
 void Player::setName(string name){
    _name = name;
}
string Player::getName(){
    return _name;

 }
void Player::printInventory() {

        for (int j = 0; j < 3; j++) {
            int index = j;

            if (index < _candy_amount) {
                cout << "[" << _inventory[index].name << "]";
            } else {
                cout << "[Empty]";
            }
    
        }
        cout << endl;
        for (int j = 3; j < 6; j++) {
            int index = j;

            if (index < _candy_amount) {
                cout << "[" << _inventory[index].name << "]";
            } else {
                cout << "[Empty]";
            }
    
        }
        cout << endl;
        for (int j = 6; j < _MAX_CANDY_AMOUNT; j++) {
            int index = j;

            if (index < _candy_amount) {
                cout << "[" << _inventory[index].name << "]";
            } else {
                cout << "[Empty]";
            }
    
        }
        cout << endl;
    }

Candy Player::findCandy(string candy_name) {
    Candy empty = {"", "", 0, ""};
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++) {
        if (_inventory[i].name == candy_name) {
            return _inventory[i];
        }
    }
    return empty;
}
bool Player::addCandy(Candy candy) {
    if (_candy_amount == 9){
        return false;
    }
    for (int i  = 0; i < _MAX_CANDY_AMOUNT; i++){
        if(_inventory[i].name == ""|| _inventory[i].description == "" || _inventory[i].price == 0 || _inventory[i].candy_type == ""){
            _inventory[i] = candy;
            _candy_amount++;
            _gold -= _inventory[i].price;
            return true;
        }
            
    }
    return false;
}
bool Player::removeCandy(const string& candyName) {
    string targetName = candyName;

    for (char& c : targetName) {
        c = tolower(c);
    }

    for (int i = 0; i < _candy_amount; i++) {
        string inventoryCandyName = _inventory[i].name;

        for (char& c : inventoryCandyName) {
            c = tolower(c);
        }

        if (inventoryCandyName == targetName) {
            for (int j = i; j < _candy_amount - 1; j++) {
                _inventory[j] = _inventory[j + 1];
            }

            _inventory[_candy_amount - 1] = Candy();

            _candy_amount--;
            return true; 
        }
    }

    return false; 
}
void Player::substituteCandy(Candy inCandy, Candy outCandy){
    for (int i =0; i < 9; i ++){
        if (_inventory[i].name == outCandy.name){
            _inventory[i] = inCandy;
        }
    }
   
}
void Player::setSkip(bool shouldSkip){
    skip = shouldSkip;
}
bool Player::isSkip(int playerNum){
    return skip;
}
bool Player::rockPaperScissors(){
    srand((unsigned)time(NULL));
    while (true) {
        cout << "Enter your choice r (rock), p (paper), or s (scissors)" << endl;
        char userChoice;
        cin >> userChoice;

        int computerChoice = rand() % 3;

        cout << "Computer's choice: ";
        switch (computerChoice) {
            case 0:
                cout << "rock";
                break;
            case 1:
                cout << "paper";
                break;
            case 2:
                cout << "scissors";
                break;
        }
        cout << endl;

        if (userChoice == 'r' && computerChoice == 2 ||
            userChoice == 'p' && computerChoice == 0 ||
            userChoice == 's' && computerChoice == 1) {
            cout << "You win!" << endl;
            return true;
            break;
        } 
        else if (userChoice == 'r' && computerChoice == 1 ||
                   userChoice == 'p' && computerChoice == 2 ||
                   userChoice == 's' && computerChoice == 0) {
            cout << "Computer wins!" << endl;
            return false;
            break;
        } 
        else {
            cout << "It's a tie! Play again!" << endl;
        }
    }
    return false;
}

