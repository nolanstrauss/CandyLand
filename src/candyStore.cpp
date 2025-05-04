#include "candyStore.h"
#include <vector>


CandyStore::CandyStore(string _name, int _pos){
    name = _name;
    pos = _pos;
    vector<Candy> candies;
}
void CandyStore::setName(string _name){
    name = _name;
}
string CandyStore::getName(){
    return name;
}
int CandyStore::getPos(){
    return pos;
}
void CandyStore::addCandies(vector<Candy> _candies){
    candies = _candies;
}
vector<Candy> CandyStore::getCandies(){
    return candies;
}
void CandyStore::printCandies(){
    for (int i = 0; i < candies.size(); i++){
        cout << candies.at(i).name << " ";
    }
    cout << endl;
}
