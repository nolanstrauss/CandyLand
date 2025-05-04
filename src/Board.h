#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "Player.h"
// #include "candyStore.h"
// #include "Deck.h"
#define RED "\033[;41m"     /* Red */
#define GREEN "\033[;42m"   /* Green */
#define BLUE "\033[;44m"    /* Blue */
#define MAGENTA "\033[;45m" /* Magenta */
#define CYAN "\033[;46m"    /* Cyan */
#define ORANGE "\033[48;2;230;115;0m"  /* Orange (230,115,0)*/
#define RESET "\033[0m"

using namespace std;

struct Tile
{
    string color;
    string tile_type;
    bool has_candy;
    Candy candy_on_tile;

};
class Board
{
private:
    const static int _BOARD_SIZE = 83;
    Tile _tiles[_BOARD_SIZE];
    const static int _MAX_CANDY_STORE = 3;
    int _candy_store_position[_MAX_CANDY_STORE];
    int _candy_store_count;
    int _player_one_position;
    int _player_two_position;
    Player _players[2];

public:
    Board();

    void resetBoard();
    void displayTile(int);
    void displayBoard();

    void addPlayers(Player);

    bool setPlayerPosition(int, int);

    int getBoardSize() const;
    int getCandyStoreCount() const;
    int getPlayerPosition(int) const;
    

    bool addCandyStore(int);
    bool isPositionCandyStore(int); 

    void addCandy(int,Candy);

    bool movePlayer(int tile_to_move_forward, int player);

    Tile getTileAtIndex(int);
};

#endif