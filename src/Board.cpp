#define RED "\033[;41m"     /* Red */
#define GREEN "\033[;42m"   /* Green */
#define BLUE "\033[;44m"    /* Blue */
#define MAGENTA "\033[;45m" /* Magenta */
#define CYAN "\033[;46m"    /* Cyan */
#define RESET "\033[0m"
#include "Board.h"
#include <vector>


Board::Board()
{
    resetBoard();
}

void Board::resetBoard()
{
    const int COLOR_COUNT = 3;
    const string COLORS[COLOR_COUNT] = {MAGENTA, GREEN, BLUE};
    string current_color;
    for (int i = 0; i < _BOARD_SIZE - 1; i++)
    {
        current_color = COLORS[i % COLOR_COUNT];
        Tile new_tile = {current_color, "regular tile"};
        _tiles[i] = new_tile;
    }
    Tile new_tile = {ORANGE, "regular tile"};
    _tiles[_BOARD_SIZE - 1] = new_tile;

    _candy_store_count = 0;
    for (int i = 0; i < _MAX_CANDY_STORE; i++)
    {
        _candy_store_position[i] = -1;
    }

    _player_one_position = 0;
    _player_two_position = 0;
}

void Board::displayTile(int position)
{
    if (position < 0 || position >= _BOARD_SIZE)
    {
        return;
    }
    Tile target = _tiles[position];
    cout << target.color << " ";
    if (position == _player_one_position)
    {
        cout << "1";
    }
    if (position == _player_two_position)
    {
        cout << "2";
    }
    else
    {
        cout << " ";
    }
    cout << " " << RESET;
}

void Board::displayBoard()
{
    // First horizontal segment
    for (int i = 0; i <= 23; i++)
    {
        displayTile(i);
    }
    cout << endl;
    // First vertical segment
    for (int i = 24; i <= 28; i++)
    {
       
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        displayTile(i);
        cout << endl;
    }
    // Second horizontal segment
    for (int i = 52; i > 28; i--)
    {
        displayTile(i);
    }
    cout << endl;
    // Second vertical segment
    for (int i = 53; i <= 57; i++)
    {
        displayTile(i);
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        cout << endl;
    }
    // Third horizontal segment
    for (int i = 58; i < _BOARD_SIZE; i++)
    {
        displayTile(i);
    }
    cout << ORANGE << "Castle" << RESET << endl;
}
void Board::addPlayers(Player player){
    if (_players[0].getName() == ""){
        _players[0] = player;
    }
    else{
        _players[1] = player;
    }
}
bool Board::setPlayerPosition(int new_position, int player)
{
    if (new_position >= 0 && new_position < _BOARD_SIZE && player == 1)
    {
        _player_one_position = new_position;
        return true;
    }
    else if (new_position >= 0 && new_position < _BOARD_SIZE && player == 2)
    {
        _player_two_position = new_position;
        return true;
    }
    return false;
}

int Board::getBoardSize() const
{
    return _BOARD_SIZE;
}

int Board::getCandyStoreCount() const
{
    return _candy_store_count;
}

int Board::getPlayerPosition(int player) const
{
    if (player == 1){
        return _player_one_position;
    }
    return _player_two_position;
    
}

bool Board::addCandyStore(int position)
{
    if (_candy_store_count >= _MAX_CANDY_STORE)
    {
        return false;
    }
    _candy_store_position[_candy_store_count] = position;
    _candy_store_count++;
    return true;
}

bool Board::isPositionCandyStore(int board_position)
{
    for (int i = 0; i < _candy_store_count; i++)
    {
        if(_candy_store_position[i] == board_position)
        {
            return true;
        }
    }
    return false;
}

void Board::addCandy(int pos,Candy candy){
    _tiles[pos].has_candy = true;
    _tiles[pos].candy_on_tile = candy;

}
bool Board::movePlayer(int tile_to_move_forward, int player)
{
    if (player == 1){
        int new_player_one_position = tile_to_move_forward + _player_one_position;
        if(new_player_one_position < 0 || new_player_one_position >= _BOARD_SIZE)
        {
            return false;
        }
        _player_one_position = new_player_one_position;
        return true;
    }
    int new_player_two_position = tile_to_move_forward + _player_two_position;
        if(new_player_two_position < 0 || new_player_two_position >= _BOARD_SIZE)
        {
            return false;
        }
        _player_two_position = new_player_two_position;
        return true;
}
Tile Board::getTileAtIndex(int index){
    return _tiles[index];
}