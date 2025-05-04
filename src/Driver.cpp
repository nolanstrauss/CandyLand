#include "Board.h"
#include "candyStore.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#define RED "\033[;41m"     /* Red */
#define GREEN "\033[;42m"   /* Green */
#define BLUE "\033[;44m"    /* Blue */
#define MAGENTA "\033[;45m" /* Magenta */
#define CYAN "\033[;46m"    /* Cyan */
#define ORANGE "\033[48;2;230;115;0m"  /* Orange (230,115,0)*/
#define RESET "\033[0m"

using namespace std;

int newStamina(Player player, Player player1, int change){
    if ( change > 0){
        player.setStamina(player.getStamina() + change);
        return player.getStamina();
    }
    player1.setStamina(player1.getStamina() + change);
    return player1.getStamina();
}

Board displayMenu(Player &player,Player &player1, int playerNum,int player1Num, Board board, vector<Candy> possible_candies, string name, string name1){
    ifstream file3("riddles.txt");
    vector<string> riddles;
    vector<string> answers;
    string line3;
    while(getline(file3,line3)){
        istringstream iss(line3);
        string riddle;
        string answer;
        getline(iss,riddle,'|');
        getline(iss,answer);
        riddles.push_back(riddle);
        answers.push_back(answer);
    }
    file3.close();
    srand((unsigned)time(NULL));
    int randNum = rand() % 100;
    int cRand = rand() % 100;
    int choice;
    
    cout << "Please select a menu option:" << endl;
    cout << "1. Draw card" << endl;
    cout << "2. Use candy" << endl;
    cout << "3. Show player stats" << endl;
    cin >> choice;
    
    
    
    if (choice == 1){
        if (player.getStamina() > 0){
            Card card;
            card = card.drawCard();
            if (board.getPlayerPosition(playerNum) == 81){
                board.setPlayerPosition(82,playerNum);
                board.displayBoard();
                return board;
            }
            if (board.getPlayerPosition(playerNum) == 80 && card.getColor() == GREEN || card.getColor() == BLUE ){
                board.setPlayerPosition(82,playerNum);
                board.displayBoard();
                return board;
            }
            if (board.getPlayerPosition(playerNum) == 79 && card.getColor() == GREEN){
                board.setPlayerPosition(82,playerNum);
                board.displayBoard();
                return board;
            }
            if (board.getPlayerPosition(playerNum) >= 76 && randNum >= 70){
                board.setPlayerPosition(82,playerNum);
                board.displayBoard();
                return board;
            }
            if (card.getColor() == "Blue" && randNum < 70){
                cout << "You drew a Bubblegum Blue card. Your game piece advances to Blue tile. Here's the updated trail:" << endl;
                if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == GREEN){
                    board.movePlayer(1,playerNum);
                    
                }
                else if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == MAGENTA){
                    board.movePlayer(2,playerNum);
                    
                }
                else if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == BLUE){
                    board.movePlayer(3,playerNum);
                    
                }
                board.displayBoard();
                return board;
            }
            if (card.getColor() == "Blue" && randNum >= 70){
                cout << "You drew a DOUBLE Bubblegum Blue card. Your game piece advances two Blue tiles. Here's the updated trail:" << endl;
                if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == GREEN){
                    board.movePlayer(4,playerNum);
                }
                else if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == MAGENTA){
                    board.movePlayer(5,playerNum);
                }
                else if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == BLUE){
                    board.movePlayer(6,playerNum);
                }
                board.displayBoard();
                
            }
            if (card.getColor() == "Green" && randNum < 70){
                cout << "You drew a Minty Green card. Your game piece advances to Green tile. Here's the updated trail:" << endl;
                if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == GREEN){
                    board.movePlayer(3,playerNum);
                }
                else if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == MAGENTA){
                    board.movePlayer(1,playerNum);
                }
                else if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == BLUE){
                    board.movePlayer(2,playerNum);
                }
                board.displayBoard();
                
            }
            if (card.getColor() == "Green" && randNum >= 70){
                cout << "You drew a DOUBLE Minty Green card. Your game piece advances two Green tiles. Here's the updated trail:" << endl;
                if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == GREEN){
                    board.movePlayer(6,playerNum);
                }
                else if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == MAGENTA){
                    board.movePlayer(4,playerNum);
                }
                else if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == BLUE){
                    board.movePlayer(5,playerNum);
                }
                board.displayBoard();
                
            }
            if (card.getColor() == "Magenta" && randNum < 70){
                cout << "You drew a Magical Magenta card. Your game piece advances to Magenta tile. Here's the updated trail:" << endl;
                if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == GREEN){
                    board.movePlayer(2,playerNum);
                }
                else if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == MAGENTA){
                    board.movePlayer(3,playerNum);
                }
                else if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == BLUE){
                    board.movePlayer(1,playerNum);
                }
                board.displayBoard();
                
            }
            if (card.getColor() == "Magenta" && randNum >= 70){
                cout << "You drew a DOUBLE Magical Magenta card. Your game piece advances two Magenta tiles. Here's the updated trail:" << endl;
                if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == GREEN){
                    board.movePlayer(5,playerNum);
                }
                else if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == MAGENTA){
                    board.movePlayer(6,playerNum);
                }
                else if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).color == BLUE){
                    board.movePlayer(4,playerNum);
                }
                board.displayBoard();
                
            }
            if (board.getPlayerPosition(playerNum) == board.getPlayerPosition(player1Num) && player1.findCandy("Robbers Repel").name == ""){
                int randGold = (rand() % 30) + 5;
                cout << "Oh no! " << name1 << " stole " << randGold << " gold from " << name << endl;
                if(player.getGold() - randGold < 0){
                    player.setGold(0);
                }
                else{
                    player.setGold(player.getGold()-randGold);
                }
            }
            if (board.getPlayerPosition(playerNum) == board.getPlayerPosition(player1Num) && player.findCandy("Robbers Repel").name == "Robbers Repel"){
                cout << name << "used Robbers Repel and protected themself from robbery!" << endl;
                board.setPlayerPosition(board.getPlayerPosition(player1Num) - 1, player1Num);
                player.removeCandy("Robbers Repel");
            }
            if (cRand > 60){
                int newRand = rand() % 150;
                if (newRand > 0 && newRand <= 30){
                    int goldRand = 1+ rand() % 10;
                    cout << "Oh no! Candy Bandits have swiped " << goldRand << " gold coins from " << name << endl;
                    if (player.getGold() - goldRand < 0){
                        player.setGold(0);
                    }
                    else{
                        player.setGold(player.getGold() - goldRand);
                    }
                }
                if (newRand > 30 && newRand <= 65){
                    char selection;
                    cout << "Oh dear! You got lost in the lollipop labyrinth! You lose a turn! Do you wish to play rock paper scissors to gain the turn back?(y/n)" << endl;
                    cin >> selection;
                    if (selection == 'y'){
                        if (player.rockPaperScissors()){
                            cout << "You won and gained your turn back!" << endl;
                        }
                        else{
                            player.setSkip(true);
                        }
                    } 
                    else{
                        player.setSkip(true);
                    }

                }
                if (newRand > 65 && newRand <= 80){
                    char selection;
                    cout << "Watch out! A candy avalanche has struck! You lose 5-10 units of stamina, and you must skip the next turn to recover. But you can recover the damage by playing Rock, Paper, Scissors. Do you wish to play?(y/n)" << endl;
                    int randStamina = rand() % 5 + 5;
                    cin >> selection;
                    player.setSkip(true);
                    if (selection == 'y'){
                        if (player.rockPaperScissors()){
                            cout << "You won and gained your resources back!" << endl;
                        }
                        else{
                            player.setStamina(player.getStamina() - randStamina);
                            cout << "Oh no! The computer won and you lost " << randStamina << " stamina!" << endl;
                        }
                    } 
                    else{
                        player.setGold(player.getGold() - randStamina);
                        cout << "You chose not to play and lost " << randStamina << " stamina!" << endl;
                    }

                }
                if (newRand > 80 && newRand <= 100){
                    char selection;
                    cout << "Oops! You are stuck in a sticky taffy trap! You're immobilzed for the next turn." << endl;
                    player.setSkip(true);
                    if (player.findCandy("Mystic Marshmallow").name != "" ){
                        cout << "There is hope though! You have a Mystic Marshmallow that can save you! do you wish to use it?(y/n)" << endl;
                        cin >> selection;
                        if (selection == 'y'){
                            player.setSkip(false);
                            player.removeCandy("Mystic Marshmallow");
                        }
                    }
                    else if (player.findCandy("Crimson Crystal").name != ""){
                        cout << "There is hope though! You have a Crimson Crystal that can save you! do you wish to use it?(y/n)" << endl;
                        cin >> selection;
                        if (selection =='y'){
                            player.setSkip(false);
                            player.removeCandy("Crimson Crystal");
                        }
                    }
                    else if(player.findCandy("Frosty Fizz").name != ""){
                        cout << "There is hope though! You have a Frosty Fizz that can save you! do you wish to use it?(y/n)" << endl;
                        cin >> selection;
                        if (selection == 'y'){
                            player.setSkip(false);
                            player.removeCandy("Frosty Fizz");
                        }
                    }
                }
            }
            if (board.getTileAtIndex(board.getPlayerPosition(playerNum)).has_candy){
                cout << "Oh no! You Landed on a gummy candy placed by " << name1 << "! It's gonna take some time to get out. Your next turn is skipped." << endl;
                player.setSkip(true);
            }
            if (board.getPlayerPosition(playerNum) == 19 || board.getPlayerPosition(playerNum) == 38 || board.getPlayerPosition(playerNum) == 60){                
                cout << "You have landed on a candy store! Do you want to visit the candy store? (y/n)" << endl;
                char choice1;
                cin >> choice1;

                if (choice1 == 'y'){
                        CandyStore store1("store1", 0);
                        vector<Candy> avCandy;
                        cout << "Here is a list of candies in the candy store:" << endl;
                        for (int i = 0; i < 4; i++){
                            avCandy.push_back(possible_candies.at(rand()%9));
                            cout << "Name: " << avCandy.at(i).name << endl;
                            cout << "Description: " << avCandy.at(i).description << endl;
                            cout << "Effect: " << avCandy.at(i).effect_type << endl;
                            cout << "Effect value: " << avCandy.at(i).effect_value << endl;
                            cout << "Candy type: " << avCandy.at(i).candy_type << endl;
                            cout << "Price: " << avCandy.at(i).price << endl;
                            cout << "-----------------------------------------------" << endl;
                            }
                            string candy_choice;
                        cout << "Which would you like to buy? Press 0 to exit." << endl;
                        cin.ignore();
                        getline(cin,candy_choice);
                        Candy candy1Choice;
                        for (int i = 0; i < 4; i++){
                            if (avCandy.at(i).name == candy_choice){
                                candy1Choice = avCandy.at(i);
                                }
                            }
                        if (candy_choice == "0"){
                            return board;
                        }
                        else{
                            if(player.getCandyAmount() < 9){
                                cout << "You have purchased " << candy_choice << "." << endl;
                                player.addCandy(candy1Choice);
                                return board;
                            }
                            else{
                                cout << "You do not have sufficent place in the candy inventory. Would you like to substiute your candy with an existing candy?(y/n)" << endl;
                                char choice;
                                cin >> choice;
                                if (choice == 'y'){
                                    cout << "Which candy would you like to substitute?" << endl;
                                    string subChoice;
                                    cin >> subChoice;
                                    for (int i =0; i < avCandy.size(); i++){
                                        if (avCandy.at(i).name == subChoice){
                                            player.substituteCandy(candy1Choice,avCandy.at(i));
                                        }
                                    }
                                    cout << "Here is your updated inventory:" << endl;
                                    player.printInventory();
                                }
                                else{
                                    return board;
                                }
                    }
                
                
                }
            }
        }
        player.setStamina(player.getStamina() - 1);
    }
    else{
        cout << "You're out of stamina! You must wait here for a move and catch your breathe." << endl;
        player.setSkip(true);
        player.setStamina(10);
    }
    return board;
}
if (choice == 2){
        string useChoice;
        Candy userChoice;
        cout << "Here is a list of your candies. Which candy do you want to use:" << endl;
        player.printInventory();
        cin.ignore();
        getline(cin,useChoice);
        for (int i = 0; i < possible_candies.size(); i++){
            if (possible_candies.at(i).name == useChoice){
                userChoice = possible_candies.at(i);
            }

        }
        player.removeCandy(useChoice);
        if (useChoice == "Treasure Hunter's Truffle"){
            int trRand = rand() % 100;
            if (trRand > 0 && trRand <= 30){
                    string answer;
                    cout << "You have landed on a hidden treasure! Solve this riddle and gain 10-30 stamina!" << endl;
                    int staminaRand = rand() % 20;
                    int sizeRand = rand() % riddles.size();
                    cout << riddles.at(sizeRand) << endl;
                    
                    cin >> answer;
                    if (answer == answers.at(sizeRand)){
                        cout << "Thats correct! You have gained " << staminaRand << " stamina." << endl;
                        if ((player.getStamina() + (staminaRand + 10)) > 100){
                            player.setStamina(100);
                        }
                        else{
                            player.setStamina(player.getStamina() + (staminaRand + 10));
                        }
                    }
                    else{
                        cout << "Sorry that is incorrect. Better luck next time!" << endl;
                    }
                }
                if (trRand > 30 && trRand <= 40){
                    string answer;
                    cout << "You have landed on a hidden treasure! Solve this riddle and gain 20-40 gold!" << endl;
                    int goldRand = rand() % 40;
                    int sizeRand = rand() % riddles.size();
                    cout << riddles.at(sizeRand) << endl;
                    cin >> answer;
                    if (answer == answers.at(sizeRand)){
                        cout << "Thats correct! You have gained " << goldRand << " gold." << endl;
                        if ((player.getGold() + (20 + goldRand)) > 100){
                            player.setGold(100);
                        }
                        else{
                            player.setGold(player.getGold() + (goldRand + 20));
                        }
                    }
                    else{
                        cout << "Sorry that is incorrect. Better luck next time!";
                    }
                }
                if (trRand > 40 && trRand <= 70){
                    Candy robbers_repel = {"Robbers Repel", "This candy acts as an anti-robbery shield, safeguarding your gold from potential theft by others during their journey. It comes into effect when another player attempts to swipe your gold while on the same tile as you.",0, "Shield",0,0};
                    string answer;
                    cout << "You have landed on a hidden treasure! Solve this riddle and aquire Robbers Repel. This candy acts as an anti-robbery shield, safeguarding your gold from potential theft by others during their journey. It comes into effect when another player attempts to swipe your gold while on the same tile as you." << endl;
                    int sizeRand = rand() % riddles.size();
                    cout << riddles.at(sizeRand) << endl;
                    cin >> answer;
                    if (answer == answers.at(sizeRand)){
                        if (player.addCandy(robbers_repel)){
                        cout << "Thats correct! You have gained Robbers Repel." << endl;
                        }
                        else{
                            vector<Candy> avCandy;
                            for (int i = 0; i < 4; i++){
                                avCandy.push_back(possible_candies.at(rand()%9));;
                        }
                            cout << "Thats correct, but you do not have sufficent place in the candy inventory. Would you like to substiute your candy with an existing candy?(y/n)" << endl;
                            char choice;
                            cin >> choice;
                            if (choice == 'y'){
                                cout << "Which candy would you like to substitute?" << endl;
                                string subChoice;
                                cin.ignore();
                                getline(cin,subChoice);
                                for (int i =0; i < avCandy.size(); i++){
                                    if (avCandy.at(i).name == subChoice){
                                        player.substituteCandy(robbers_repel,avCandy.at(i));
                                    }
                                }
                                cout << "Here is your updated inventory:" << endl;
                                player.printInventory();
                            }
                        }
                    }
                    else{
                        cout << "Sorry that is incorrect. Better luck next time!";
                    }
                }
                if (trRand > 70 && trRand <= 100){
                    Candy jelly = {"The Jellybean of Vigor", "Using the Jellybean of Vigor, you can restore 50 units of stamina",0,"magical",50};
                    string answer;
                    int candyRand = rand() % 100;
                    if (candyRand > 30){
                        cout << "You have landed on a hidden treasure! Solve this riddle and aquire The Jellybean of Vigor." << endl;
                        int sizeRand = rand() % riddles.size();
                        cout << riddles.at(sizeRand) << endl;
                        cin >> answer;
                        if (answer == answers.at(sizeRand)){
                            if (player.addCandy(jelly)){
                                cout << "Thats correct! You have gained The Jellybean of Vigor." << endl;
                            }
                             else{
                                vector<Candy> avCandy;
                                for (int i = 0; i < 4; i++){
                                    avCandy.push_back(possible_candies.at(rand()%9));;
                            }
                                cout << "Thats correct, but you do not have sufficent place in the candy inventory. Would you like to substiute your candy with an existing candy?(y/n)" << endl;
                                char choice;
                                cin >> choice;
                                if (choice == 'y'){
                                    cout << "Which candy would you like to substitute?" << endl;
                                    string subChoice;
                                    cin.ignore();
                                    getline(cin,subChoice);
                                    for (int i =0; i < avCandy.size(); i++){
                                        if (avCandy.at(i).name == subChoice){
                                            player.substituteCandy(jelly,avCandy.at(i));
                                        }
                                    }
                                    cout << "Here is your updated inventory:" << endl;
                                    player.printInventory();
                                }
                            }
                    }
                    else{
                        cout << "Sorry that is incorrect. Better luck next time!";
                    }
                }
                    else{
                        Candy truffle = {"Treasure Hunter's Truffle", "Discover hidden treasure instantly",0,"other",0};
                        cout << "You have landed on a hidden treasure! Solve this riddle and aquire The Treasure Hunter's Truffle." << endl;
                        int sizeRand = rand() % riddles.size();
                            cout << riddles.at(sizeRand) << endl;
                            cin >> answer;
                            if (answer == answers.at(sizeRand)){
                                if (player.addCandy(truffle)){
                                    cout << "Thats correct! You have gained Treasure Hunter's Truffle." << endl;
                                }
                                else{
                                    vector<Candy> avCandy;
                                    for (int i = 0; i < 4; i++){
                                        avCandy.push_back(possible_candies.at(rand()%9));;
                                }
                                    cout << "Thats correct, but you do not have sufficent place in the candy inventory. Would you like to substiute your candy with an existing candy?(y/n)" << endl;
                                    char choice;
                                    cin >> choice;
                                    if (choice == 'y'){
                                        cout << "Which candy would you like to substitute?" << endl;
                                        string subChoice;
                                        cin.ignore();
                                        getline(cin,subChoice);
                                        for (int i =0; i < avCandy.size(); i++){
                                            if (avCandy.at(i).name == subChoice){
                                                player.substituteCandy(jelly,avCandy.at(i));
                                            }
                                        }
                                        cout << "Here is your updated inventory:" << endl;
                                        player.printInventory();
                                    }
                            }
                    }
                    else{
                        cout << "Sorry that is incorrect. Better luck next time!";
                    }

                }
            }
        }
        if (userChoice.candy_type == "gummy"){
        cout << "On which tile do you want to place your " << userChoice.name << " - " << userChoice.candy_type << "?" << endl;
        int candyTile;
        cin >> candyTile;
        board.addCandy(candyTile,userChoice);
        cout << "You have successfully placed " << userChoice.candy_type << " candy on tile " << candyTile << ". Any player that lands on the " << userChoice.candy_type << " tile will be obstructed from advancing past the tile for two moves." << endl;
        }
        else if (userChoice.candy_type == "magical"){
            cout << "You have used " << userChoice.name << ". This has increased your stamina by " << userChoice.effect_value << " points." << endl;
            
            int newStamina = player.getStamina() + userChoice.effect_value;
            if (newStamina > 100){
                player.setStamina(100);
            }
            else{
                player.setStamina(newStamina);
            }
        }
        else if (userChoice.candy_type == "poison"){
            cout << "Do you want to use " << userChoice.name << " candy against your opponent?(y/n)" << endl;
            char choice;
            cin >> choice;
            if (choice == 'y'){
                if (userChoice.name == "Lucky Licorice" && player1.findCandy("Caramel Comet").name != "" || player1.findCandy("Sparkling Sapphire").name != "" || player1.findCandy("Bubblegum Blast").name != ""){
                    string protCandy;
                        if(player1.findCandy("Bubblegum Blast").name != ""){
                            protCandy = "Bubblegum Blast";
                        }
                        else if (player1.findCandy("Sparkling Sapphire").name != ""){
                            protCandy = "Sparkling Sapphire";
                        }
                        else if (player1.findCandy("Caramel Comet").name != ""){
                            protCandy = "Caramel Comet";
                        }
                    
                    cout << "You have used Lucky Licorice candy but your opponent has "<< protCandy << " candy to protect against your poison candy." << endl;
                    player1.removeCandy(protCandy);
                }
                else if (userChoice.name == "Venomous Vortex" && player1.findCandy("Caramel Comet").name != "" || player1.findCandy("Sparkling Sapphire").name != ""){
                    string protCandy;
                        if (player1.findCandy("Sparkling Sapphire").name != ""){
                            protCandy = "Sparkling Sapphire";
                        }
                        else if (player1.findCandy("Caramel Comet").name != ""){
                            protCandy = "Caramel Comet";
                        }
                    cout << "You have used Venomous Vortex candy but your opponent has "<< protCandy << " candy to protect against your poison candy." << endl;
                    player1.removeCandy(protCandy);
                }
                else if (userChoice.name == "Toxic Taffy" && player1.findCandy("Caramel Comet").name != ""){
                    cout << "You have used Venomous Vortex candy but your opponent has Caramel Comet candy to protect against your poison candy." << endl;
                    player1.removeCandy("Caramel Comet");
                }
                else{
                    cout << "You have used " << userChoice.name << " against your opponent. They have lost " << userChoice.effect_value <<" stamina points." << endl;
                    if (player1.getStamina() - userChoice.effect_value < 0){
                        player1.setStamina(0);
                    }
                    else{
                        player1.setStamina(player1.getStamina() + userChoice.effect_value);
                    }
                }
            }
        }
}
if (choice == 3){
    if (player.getGold() >= 0 && player.getStamina() >= 0){
        cout << "Here are your stats:" << endl;
        cout << "Name: " << name << endl;
        cout << "Character Name: " << player.getName() << endl;
        cout << "Stamina: " << player.getStamina() << endl;
        cout << "Gold:" << player.getGold() << endl;
        cout << "Candies: " << endl;
        player.printInventory();
   }
    if (player.getGold() < 0 && player.getStamina() >= 0){
        cout << "Here are your stats:" << endl;
        cout << "Name: " << name << endl;
        cout << "Character Name: " << player.getName() << endl;
        cout << "Stamina: " << player.getStamina() << endl;
        cout << "Gold: 0" << endl;
        cout << "Candies: " << endl;
        player.printInventory();
   }
   if (player.getStamina() < 0 && player.getGold() >= 0){
        cout << "Here are your stats:" << endl;
        cout << "Name: " << name << endl;
        cout << "Character Name: " << player.getName() << endl;
        cout << "Stamina: 0" << endl;
        cout << "Gold: " << player.getGold() << endl;
        cout << "Candies: " << endl;
        player.printInventory();
   }
   if (player.getStamina() < 0 && player.getGold() < 0){
        cout << "Here are your stats:" << endl;
        cout << "Name: " << name << endl;
        cout << "Character Name: " << player.getName() << endl;
        cout << "Stamina: 0" << endl;
        cout << "Gold: 0" << endl;
        cout << "Candies: " << endl;
        player.printInventory();
   }
   
}
   
return board;
}

int main(){
    srand((unsigned)time(NULL));
    vector<Candy> possible_candies;
    ifstream file("candies.txt");

    string header;
    getline(file, header);

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        Candy candy;

        string str_effect_value;
        string str_price;

        getline(iss, candy.name, '|');
        getline(iss, candy.description, '|');
        getline(iss, candy.effect_type, '|');
        iss >> candy.effect_value;
        iss.ignore(); 
        getline(iss, candy.candy_type, '|');
        iss >> candy.price;
       

        possible_candies.push_back(candy);
    }
    file.close();

    vector<Player> possible_players;
    ifstream file2("characters.txt");

    string header2;
    getline(file2,header2);

    string line2;
    while (getline(file2, line2)){
        istringstream iss(line2);
        string name;
        int stamina;
        double gold;
        string candy;
        Candy candies[9];

        getline(iss, name, '|');
        iss >> stamina;
        iss.ignore();
        iss >> gold;
        iss.ignore();
        int j = 0;
        while (getline(iss,candy, ',')){
            for (int i = 0; i < possible_candies.size(); i++){
                if (possible_candies.at(i).name == candy){
                    candies[j] = possible_candies.at(i);
                    j++;
                }
        }
        }
        Player player(name, stamina, gold,candies,9);
        possible_players.push_back(player);
    }
    file2.close();
    ifstream file3("riddles.txt");
    vector<string> riddles;
    vector<string> answers;
    string line3;
    while(getline(file3,line3)){
        istringstream iss(line3);
        string riddle;
        string answer;
        getline(iss,riddle,'|');
        getline(iss,answer);
        riddles.push_back(riddle);
        answers.push_back(answer);
    }
    file3.close();
    cout << "Welcome to the game of candyland. This is a two player game." <<endl;

    string player1Name;
    cout << "Enter player name:" << endl;
    cin >> player1Name;

    cout << "Awesome! Here is a list of characters a player can select from:" << endl;

    for (int i = 0; i < possible_players.size(); i++){
        cout << "Name: " << possible_players.at(i).getName() << endl;
        cout << "Stamina: " << possible_players.at(i).getStamina() << endl;
        cout << "Gold: " << possible_players.at(i).getGold() << endl;
        cout << "Candies: " << endl;
        possible_players.at(i).printInventory();
        cout << "-----------------------------------------------" << endl;
        
    }
    cout << "The selected character is" << endl;
    string player1choice;
    Player player1Character;
    cin >> player1choice;

    player1Character.setName(player1choice);
    for(int i = 0; i < possible_players.size(); i++){
        if(player1Character.getName() == possible_players.at(i).getName()){
            player1Character = possible_players.at(i);
        }
    }
   cout << "Do you want to visit the candy store? (y/n)" << endl;
   char choice1;
   cin >> choice1;

   if (choice1 == 'y'){
        CandyStore store1("store1", 1);
        vector<Candy> avCandy;
        cout << "Here is a list of candies in the candy store:" << endl;
        for (int i = 0; i < 4; i++){
            avCandy.push_back(possible_candies.at(rand()%9));
            cout << "Name: " << avCandy.at(i).name << endl;
            cout << "Description: " << avCandy.at(i).description << endl;
            cout << "Effect: " << avCandy.at(i).effect_type << endl;
            cout << "Effect value: " << avCandy.at(i).effect_value << endl;
            cout << "Candy type: " << avCandy.at(i).candy_type << endl;
            cout << "Price: " << avCandy.at(i).price << endl;
            cout << "-----------------------------------------------" << endl;
            }
        string candy_choice;
        cout << "Which would you like to buy? Press 0 to exit." << endl;
        cin.ignore();
        getline(cin,candy_choice);
        Candy candy1Choice;
        for (int i = 0; i < 4; i++){
            if (avCandy.at(i).name == candy_choice){
                candy1Choice = avCandy.at(i);
                }
            }
        if (candy_choice == "0"){
            return 0;
        }
        else{
            if(player1Character.getCandyAmount() < 9){
                cout << "You have purchased " << candy_choice << "." << endl;
                player1Character.addCandy(candy1Choice);
            }
            else{
                cout << "You do not have sufficent place in the candy inventory. Would you like to substiute your candy with an existing candy?(y/n)" << endl;
                char choice;
                cin >> choice;
                if (choice == 'y'){
                    cout << "Which candy would you like to substitute?" << endl;
                    string subChoice;
                    cin >> subChoice;
                    for (int i =0; i < avCandy.size(); i++){
                        if (avCandy.at(i).name == subChoice){
                            player1Character.substituteCandy(candy1Choice,avCandy.at(i));
                        }
                    }
                    cout << "Here is your updated inventory:" << endl;
                    player1Character.printInventory();
                }
            }
            
            
        }
   }

    string player2Name;
    cout << "Enter player name:" << endl;
    cin >> player2Name;

    cout << "Awesome! Here is a list of characters a player can select from:" << endl;

    for (int i = 0; i < possible_players.size(); i++){
        cout << "Name: " << possible_players.at(i).getName() << endl;
        cout << "Stamina: " << possible_players.at(i).getStamina() << endl;
        cout << "Gold: " << possible_players.at(i).getGold() << endl;
        cout << "Candies: " << endl;
        possible_players.at(i).printInventory();
        cout << "-----------------------------------------------" << endl;
        
    }
   cout << "The selected character is" << endl;
   Player player2Character;
   string player2choice;
   cin >> player2choice;
   player2Character.setName(player2choice);
    for(int i = 0; i < possible_players.size(); i++){
        if(player2Character.getName() == possible_players.at(i).getName()){
            player2Character = possible_players.at(i);
        }
    }

   cout << "Do you want to visit the candy store? (y/n)" << endl;
   char choice;
   cin >> choice;

   if (choice == 'y'){
        CandyStore store1("store1", 1);
        vector<Candy> avCandy;
        cout << "Here is a list of candies in the candy store:" << endl;
        for (int i = 0; i < 4; i++){
            avCandy.push_back(possible_candies.at(rand()%9));
            cout << "Name: " << avCandy.at(i).name << endl;
            cout << "Description: " << avCandy.at(i).description << endl;
            cout << "Effect: " << avCandy.at(i).effect_type << endl;
            cout << "Effect value: " << avCandy.at(i).effect_value << endl;
            cout << "Candy type: " << avCandy.at(i).candy_type << endl;
            cout << "Price: " << avCandy.at(i).price << endl;
            cout << "-----------------------------------------------" << endl;
            }
        string candy_choice;
        cout << "Which would you like to buy? Press 0 to exit." << endl;
        cin.ignore();
        getline(cin,candy_choice);
        Candy candyChoice;
        for (int i = 0; i < 4; i++){
            if (avCandy.at(i).name == candy_choice){
                candyChoice = avCandy.at(i);
                }
            }
        if (candy_choice == "0"){
            return 0;
        }
        else{
            if(player2Character.getCandyAmount() < 9){
                cout << "You have purchased " << candy_choice << "." << endl;
                player2Character.addCandy(candyChoice);
            }
            else{
                cout << "You do not have sufficent place in the candy inventory. Would you like to substiute your candy with an existing candy?(y/n)" << endl;
                char choice;
                cin >> choice;
                if (choice == 'y'){
                    cout << "Which candy would you like to substitute?" << endl;
                    string subChoice;
                    cin >> subChoice;
                    for (int i =0; i < avCandy.size(); i++){
                        if (avCandy.at(i).name == subChoice){
                            player2Character.substituteCandy(candyChoice,avCandy.at(i));
                        }
                    }
                    cout << "Here is your updated inventory:" << endl;
                    player2Character.printInventory();
                }
            }
            
        }
   }
   cout << "Let's begin the game. Here is the board:" << endl;
   Board board;
   board.resetBoard();
   board.addPlayers(player1Character);
   board.addPlayers(player2Character);
   board.displayBoard();
   bool won = false;
   int shortCutRand = rand() % 81;
   int iceCreamRand = rand() % 81;
   int gumDropRand = rand() % 81;
   int gingerRand = rand() % 81;
   int rand1Tr = rand() % 81;
   int rand2Tr = rand() % 81;
   int rand3Tr = rand() % 81;


   while(!won){
        if(!player1Character.isSkip(1)){
            cout << "It's " << player1Name << "'s turn" << endl;
            board = displayMenu(player1Character,player2Character,1,2,board,possible_candies, player1Name,player2Name);
            cout << shortCutRand << " " << iceCreamRand << " " << gingerRand << " " << gumDropRand << endl;
            if (board.getPlayerPosition(1) == shortCutRand){
                cout << "You landed on the Shortcut Tile! This is like finding a hidden passage through the candy-coated landscape. You advance 4 tiles." << endl;
                if (board.getPlayerPosition(1) >= 78){
                    board.setPlayerPosition(82,1);
                    board.displayBoard();

                }
                else{
                    board.setPlayerPosition(board.getPlayerPosition(1) + 4, 1);
                    board.displayBoard();

                }        
            }
            if (board.getPlayerPosition(1) == iceCreamRand){
                cout << "You landed on the Ice Cream Shop Tile! Take another turn." << endl;
                board = displayMenu(player1Character,player2Character,1,2,board,possible_candies, player1Name,player2Name);
            }
            if (board.getPlayerPosition(1) == gumDropRand){
                cout << "You landed on the Gum Drop Forest Tile! You'll be taken four tiles back, losing a random amount of gold coins (5 - 10 gold)." << endl;
                if (board.getPlayerPosition(1) <=4){
                    board.setPlayerPosition(0, 1);
                    board.displayBoard();

                }
                else{
                    board.setPlayerPosition(board.getPlayerPosition(1) - 4, 1);
                    board.displayBoard();

                }
            }
            if (board.getPlayerPosition(1) == gingerRand){
                cout << "You landed on the Ginger Bread House Tile! You were a little hungry and hung around too long and missed your turn!" << endl;
                player1Character.setSkip(true);
            }
            if (board.getPlayerPosition(1) == rand1Tr ||board.getPlayerPosition(1) == rand2Tr ||board.getPlayerPosition(1) == rand3Tr){
                int trRand = rand() % 100;
                if (trRand > 0 && trRand <= 30){
                    string answer;
                    cout << "You have landed on a hidden treasure! Solve this riddle and gain 10-30 stamina!" << endl;
                    int staminaRand = 10 + rand() % 30;
                    int sizeRand = rand() % riddles.size();
                    cout << riddles.at(sizeRand) << endl;
                    
                    cin >> answer;
                    if (answer == answers.at(sizeRand)){
                        cout << "Thats correct! You have gained " << staminaRand << " stamina." << endl;
                        if ((player1Character.getStamina() + staminaRand) > 100){
                            player1Character.setStamina(100);
                        }
                        else{
                            player1Character.setStamina(player1Character.getStamina() + staminaRand);
                        }
                    }
                    else{
                        cout << "Sorry that is incorrect. Better luck next time!" << endl;
                    }
                }
                if (trRand > 30 && trRand <= 40){
                    string answer;
                    cout << "You have landed on a hidden treasure! Solve this riddle and gain 20-40 gold!" << endl;
                    int goldRand = 20 + rand() % 40;
                    int sizeRand = rand() % riddles.size();
                    cout << riddles.at(sizeRand) << endl;
                    cin >> answer;
                    if (answer == answers.at(sizeRand)){
                        cout << "Thats correct! You have gained " << goldRand << " gold." << endl;
                        if ((player1Character.getGold() + goldRand) > 100){
                            player1Character.setGold(100);
                        }
                        else{
                            player1Character.setStamina(player1Character.getStamina() + goldRand);
                        }
                    }
                    else{
                        cout << "Sorry that is incorrect. Better luck next time!";
                    }
                }
                if (trRand > 40 && trRand <= 70){
                    Candy robbers_repel = {"Robbers Repel", "This candy acts as an anti-robbery shield, safeguarding your gold from potential theft by others during their journey. It comes into effect when another player attempts to swipe your gold while on the same tile as you.",0, "Shield",0,0};
                    string answer;
                    cout << "You have landed on a hidden treasure! Solve this riddle and aquire Robbers Repel. This candy acts as an anti-robbery shield, safeguarding your gold from potential theft by others during their journey. It comes into effect when another player attempts to swipe your gold while on the same tile as you." << endl;
                    int sizeRand = rand() % riddles.size();
                    cout << riddles.at(sizeRand) << endl;
                    cin >> answer;
                    if (answer == answers.at(sizeRand)){
                        if (player1Character.addCandy(robbers_repel)){
                        cout << "Thats correct! You have gained Robbers Repel." << endl;
                        }
                        else{
                            vector<Candy> avCandy;
                            for (int i = 0; i < 4; i++){
                                avCandy.push_back(possible_candies.at(rand()%9));;
                        }
                            cout << "Thats correct, but you do not have sufficent place in the candy inventory. Would you like to substiute your candy with an existing candy?(y/n)" << endl;
                            char choice;
                            cin >> choice;
                            if (choice == 'y'){
                                cout << "Which candy would you like to substitute?" << endl;
                                string subChoice;
                                cin.ignore();
                                getline(cin,subChoice);
                                for (int i =0; i < avCandy.size(); i++){
                                    if (avCandy.at(i).name == subChoice){
                                        player1Character.substituteCandy(robbers_repel,avCandy.at(i));
                                    }
                                }
                                cout << "Here is your updated inventory:" << endl;
                                player1Character.printInventory();
                            }
                        }
                    }
                    else{
                        cout << "Sorry that is incorrect. Better luck next time!";
                    }
                }
                if (trRand > 70 && trRand <= 100){
                    Candy jelly = {"The Jellybean of Vigor", "Using the Jellybean of Vigor, you can restore 50 units of stamina",0,"magical",50};
                    string answer;
                    int candyRand = rand() % 100;
                    if (candyRand > 30){
                        cout << "You have landed on a hidden treasure! Solve this riddle and aquire The Jellybean of Vigor." << endl;
                        int sizeRand = rand() % riddles.size();
                        cout << riddles.at(sizeRand) << endl;
                        cin >> answer;
                        if (answer == answers.at(sizeRand)){
                            if (player1Character.addCandy(jelly)){
                                cout << "Thats correct! You have gained The Jellybean of Vigor." << endl;
                            }
                             else{
                                vector<Candy> avCandy;
                                for (int i = 0; i < 4; i++){
                                    avCandy.push_back(possible_candies.at(rand()%9));;
                            }
                                cout << "Thats correct, but you do not have sufficent place in the candy inventory. Would you like to substiute your candy with an existing candy?(y/n)" << endl;
                                char choice;
                                cin >> choice;
                                if (choice == 'y'){
                                    cout << "Which candy would you like to substitute?" << endl;
                                    string subChoice;
                                    cin.ignore();
                                    getline(cin,subChoice);
                                    for (int i =0; i < avCandy.size(); i++){
                                        if (avCandy.at(i).name == subChoice){
                                            player1Character.substituteCandy(jelly,avCandy.at(i));
                                        }
                                    }
                                    cout << "Here is your updated inventory:" << endl;
                                    player1Character.printInventory();
                                }
                            }
                    }
                    else{
                        cout << "Sorry that is incorrect. Better luck next time!";
                    }
                }
                    else{
                        Candy truffle = {"Treasure Hunter's Truffle", "Discover hidden treasure instantly",0,"other",0};
                        cout << "You have landed on a hidden treasure! Solve this riddle and aquire The Treasure Hunter's Truffle." << endl;
                        int sizeRand = rand() % riddles.size();
                            cout << riddles.at(sizeRand) << endl;
                            cin >> answer;
                            if (answer == answers.at(sizeRand)){
                                if (player1Character.addCandy(truffle)){
                                    cout << "Thats correct! You have gained Treasure Hunter's Truffle." << endl;
                                }
                                else{
                                    vector<Candy> avCandy;
                                    for (int i = 0; i < 4; i++){
                                        avCandy.push_back(possible_candies.at(rand()%9));;
                                }
                                    cout << "Thats correct, but you do not have sufficent place in the candy inventory. Would you like to substiute your candy with an existing candy?(y/n)" << endl;
                                    char choice;
                                    cin >> choice;
                                    if (choice == 'y'){
                                        cout << "Which candy would you like to substitute?" << endl;
                                        string subChoice;
                                        cin.ignore();
                                        getline(cin,subChoice);
                                        for (int i =0; i < avCandy.size(); i++){
                                            if (avCandy.at(i).name == subChoice){
                                                player1Character.substituteCandy(jelly,avCandy.at(i));
                                            }
                                        }
                                        cout << "Here is your updated inventory:" << endl;
                                        player1Character.printInventory();
                                    }
                            }
                    }
                    else{
                        cout << "Sorry that is incorrect. Better luck next time!";
                    }

                }
            }
            
        }
        if(board.getPlayerPosition(1) >= 82){
                cout << player1Name << " WINS!! Better luck next time " << player2Name << endl; 
                won = true;
                break;
            }
        }
        else{
            cout << "Sorry " << player1Name << " your turn was skipped!" << endl;
            player1Character.setSkip(false);
        
        }
        if (!player2Character.isSkip(2)){
            cout << "It's " << player2Name << "'s turn" << endl;
            board = displayMenu(player2Character,player1Character,2,1,board,possible_candies, player2Name,player1Name);
            cout << shortCutRand << " " << iceCreamRand << " " << gingerRand << " " << gumDropRand << endl;
            if (board.getPlayerPosition(2) == shortCutRand){
                cout << "You landed on the shortcut tile! This is like finding a hidden passage through the candy-coated landscape. You advance 4 tiles." << endl;
                if (board.getPlayerPosition(2) >= 78){
                    board.setPlayerPosition(82,2);
                    board.displayBoard();

                }
                else{
                    board.setPlayerPosition(board.getPlayerPosition(2) + 4,2);
                    board.displayBoard();
                }
            }
            if (board.getPlayerPosition(2) == iceCreamRand){
                cout << "You landed on the Ice Cream Shop Tile! Take another turn." << endl;
                board = displayMenu(player2Character,player1Character,2,1,board,possible_candies, player2Name, player1Name);
            }
            if (board.getPlayerPosition(2) == gumDropRand){
                cout << "You landed on the Gum Drop Forest Tile! You'll be taken four tiles back, losing a random amount of gold coins (5 - 10 gold)." << endl;
                if (board.getPlayerPosition(2) <=4){
                    board.setPlayerPosition(0, 2);
                    board.displayBoard();

                }
                else{
                    board.setPlayerPosition(board.getPlayerPosition(2) - 4, 2);
                    board.displayBoard();

                }
            }
            if (board.getPlayerPosition(2) == gingerRand){
                cout << "You landed on the Ginger Bread House Tile! You were a little hungry and hung around too long and missed your turn!" << endl;
                player2Character.setSkip(true);
            }
            if (board.getPlayerPosition(2) == rand1Tr ||board.getPlayerPosition(2) == rand2Tr ||board.getPlayerPosition(2) == rand3Tr){
                int trRand = rand() % 100;
                if (trRand > 0 && trRand <= 30){
                    string answer;
                    cout << "You have landed on a hidden treasure! Solve this riddle and gain 10-30 stamina!" << endl;
                    int staminaRand = 10 + rand() % 30;
                    int sizeRand = rand() % riddles.size();
                    cout << riddles.at(sizeRand) << endl;
                    cin >> answer;
                    if (answer == answers.at(sizeRand)){
                        cout << "Thats correct! You have gained " << staminaRand << " stamina." << endl;
                        if ((player2Character.getStamina() + staminaRand) > 100){
                            player2Character.setStamina(100);
                        }
                        else{
                            player2Character.setStamina(player2Character.getStamina() + staminaRand);
                        }
                    }
                    else{
                        cout << "Sorry that is incorrect. Better luck next time!" << endl;
                    }
                }
                if (trRand > 30 && trRand <= 40){
                    string answer;
                    cout << "You have landed on a hidden treasure! Solve this riddle and gain 20-40 gold!" << endl;
                    int goldRand = 20 + rand() % 40;
                    int sizeRand = rand() % riddles.size();
                    cout << riddles.at(sizeRand) << endl;
                    cin >> answer;
                    if (answer == answers.at(sizeRand)){
                        cout << "Thats correct! You have gained " << goldRand << " gold." << endl;
                        if ((player2Character.getGold() + goldRand) > 100){
                            player2Character.setGold(100);
                        }
                        else{
                            player2Character.setStamina(player2Character.getStamina() + goldRand);
                        }
                    }
                    else{
                        cout << "Sorry that is incorrect. Better luck next time!" << endl;
                    }
                }
                if (trRand > 40 && trRand <= 70){
                    Candy robbers_repel = {"Robbers Repel", "This candy acts as an anti-robbery shield, safeguarding your gold from potential theft by others during their journey. It comes into effect when another player attempts to swipe your gold while on the same tile as you.",0, "Shield",0,0};
                    string answer;
                    cout << "You have landed on a hidden treasure! Solve this riddle and aquire Robbers Repel. This candy acts as an anti-robbery shield, safeguarding your gold from potential theft by others during their journey. It comes into effect when another player attempts to swipe your gold while on the same tile as you." << endl;
                    int sizeRand = rand() % riddles.size();
                    cout << riddles.at(sizeRand) << endl;
                    cin >> answer;
                    if (answer == answers.at(sizeRand)){
                        if(player2Character.addCandy(robbers_repel)){
                            cout << "Thats correct! You have gained Robbers Repel." << endl;
                        }
                        else{
                            vector<Candy> avCandy;
                            for (int i = 0; i < 4; i++){
                                avCandy.push_back(possible_candies.at(rand()%9));;
                        }
                            cout << "You do not have sufficent place in the candy inventory. Would you like to substiute your candy with an existing candy?(y/n)" << endl;
                            char choice;
                            cin >> choice;
                            if (choice == 'y'){
                                cout << "Which candy would you like to substitute?" << endl;
                                string subChoice;
                                cin.ignore();
                                getline(cin,subChoice);
                                for (int i =0; i < avCandy.size(); i++){
                                    if (avCandy.at(i).name == subChoice){
                                        player2Character.substituteCandy(robbers_repel,avCandy.at(i));
                                    }
                                }
                                cout << "Here is your updated inventory:" << endl;
                                player2Character.printInventory();
                            }
                        }
                    }
                    else{
                        cout << "Sorry that is incorrect. Better luck next time!" << endl;
                    }
                }
                if (trRand > 70 && trRand <= 100){
                    Candy jelly = {"The Jellybean of Vigor", "Using the Jellybean of Vigor, you can restore 50 units of stamina",0,"magical",50};
                    string answer;
                    int candyRand = rand() % 100;
                    if (candyRand > 30){
                        cout << "You have landed on a hidden treasure! Solve this riddle and aquire The Jellybean of Vigor." << endl;
                        int sizeRand = rand() % riddles.size();
                        cout << riddles.at(sizeRand) << endl;
                        cin >> answer;
                        if (answer == answers.at(sizeRand)){
                            if(player2Character.addCandy(jelly)){
                                cout << "Thats correct! You have gained The Jellybean of Vigor." << endl;
                            }
                            else{
                                vector<Candy> avCandy;
                                for (int i = 0; i < 4; i++){
                                    avCandy.push_back(possible_candies.at(rand()%9));;
                            }
                                cout << "You do not have sufficent place in the candy inventory. Would you like to substiute your candy with an existing candy?(y/n)" << endl;
                                char choice;
                                cin >> choice;
                                if (choice == 'y'){
                                    cout << "Which candy would you like to substitute?" << endl;
                                    string subChoice;
                                    cin.ignore();
                                    getline(cin,subChoice);
                                    for (int i =0; i < avCandy.size(); i++){
                                        if (avCandy.at(i).name == subChoice){
                                            player2Character.substituteCandy(jelly,avCandy.at(i));
                                        }
                                    }
                                    cout << "Here is your updated inventory:" << endl;
                                    player2Character.printInventory();
                                }
                            }
                    }
                    else{
                        cout << "Sorry that is incorrect. Better luck next time!" << endl;
                    }
                }
                else{
                    Candy truffle = {"Treasure Hunter's Truffle", "Discover hidden treasure instantly",0,"other",0};
                    cout << "You have landed on a hidden treasure! Solve this riddle and aquire The Treasure Hunter's Truffle." << endl;
                    int sizeRand = rand() % riddles.size();
                        cout << riddles.at(sizeRand) << endl;
                        cin >> answer;
                        if (answer == answers.at(sizeRand)){
                            if(player2Character.addCandy(truffle)){
                                cout << "Thats correct! You have gained Treasure Hunter's Truffle." << endl;
                            }
                            else{
                                vector<Candy> avCandy;
                                for (int i = 0; i < 4; i++){
                                    avCandy.push_back(possible_candies.at(rand()%9));;
                            }
                                cout << "You do not have sufficent place in the candy inventory. Would you like to substiute your candy with an existing candy?(y/n)" << endl;
                                char choice;
                                cin >> choice;
                                if (choice == 'y'){
                                    cout << "Which candy would you like to substitute?" << endl;
                                    string subChoice;
                                    cin.ignore();
                                    getline(cin,subChoice);
                                    for (int i =0; i < avCandy.size(); i++){
                                        if (avCandy.at(i).name == subChoice){
                                            player2Character.substituteCandy(truffle,avCandy.at(i));
                                        }
                                    }
                                    cout << "Here is your updated inventory:" << endl;
                                    player2Character.printInventory();
                                }
                            }
                    }
                    else{
                        cout << "Sorry that is incorrect. Better luck next time!" << endl;
                    }

                }
            }
            
        }
        }
        else{
            cout << "Sorry " << player2Name << " your turn was skipped!" << endl;
            player2Character.setSkip(false);
        }
   
        if (board.getPlayerPosition(2) >= 82){
                    cout << player2Name << " WINS!! Better luck next time " << player1Name << endl; 
                    won = true;
                    break;
        }
   }

}