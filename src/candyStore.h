#ifndef CANDYSTORE_H
#define CANDYSTORE_H
#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

class CandyStore{
    private:
        const static int CANDY_OFFERED = 4;
        vector<Candy> candies;
        string name;
        int pos;

    public:
        CandyStore(string,int);
        void setName(string);
        string getName();

        int getPos();

        void addCandies(vector<Candy>);
        vector<Candy> getCandies();
        void printCandies();
};
#endif

