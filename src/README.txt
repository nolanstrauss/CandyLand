------------------------
HOW TO COMPILE AND RUN
------------------------
Compile: g++ -std=c++11 Driver.cpp candyStore.cpp Board.cpp Card.cpp Player.cpp

Run: ./a.out
------------------------
DEPENDENCIES
------------------------
Board.h, Player.h, candyStore.h, Card.h, candies.txt, characters.txt, and riddles.txt must be in the same
directory as the cpp files in order to compile.
------------------------
SUBMISSION INFORMATION
------------------------
CSCI1300 Fall 2023 Project 2
Author: Nolan Strauss
Recitation: 401 - Mahidhara Reddy Kankara
Date: Dec 7, 2023
------------------------
ABOUT THIS PROJECT
------------------------
This project implements an interactive board game fashioned after the game
Candy Land. This project acts as a two player competition game as the users maneuver the 
unpredictable board. Each user draws a card with the color magenta, green, or blue causing
them to advance to the nearest tile in front of them with the color drawn. With the prospect
of double cards, calamaties, hidden treasure, special tiles, and candy stores-in which the player
can purchase candies of different abilities to use throughout the game-each run of this game is different.
