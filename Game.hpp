/*********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Header file for the Game class. Contains functions 
**               that play the game by determining if the user has run
**               out of steps or already met the objective, perform an
**               action in a space, move the player to a new space, 
**               and print the map with the player's location.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Menu.hpp"
#include "Space.hpp"
#include "MainHall.hpp"
#include "Kitchen.hpp"
#include "Library.hpp"
#include "Courtyard.hpp"
#include "DiningRoom.hpp"
#include "TrainingArea.hpp"
#include "Tower.hpp"
#include "Player.hpp"

#include <iostream>

using std::cout;
using std::endl;

//enum for determining action the player will perform
enum PlayerAction {PLAY_EVENT = 1, PRINT_ITEMS, USE_ITEM, 
                   VIEW_MAP, MOVE, QUIT};

//enum for determining what direction the player will move in
enum MoveDirection {TOP = 1, RIGHT, LEFT, BOTTOM};

class Game
{
    private:
        Space *mainHall;
        Space *library;
        Space *diningRoom;
        Space *kitchen;
        Space *courtyard;
        Space *trainingArea;
        Space *tower;

        Space *currentPosition;
        Player *user;

        Menu gameMenu;

        bool quit;
        bool performedEvent;

    public:
        Game();

        void playGame();
        void performAction();
        void movePlayer();
        void printMap();

        ~Game();
};

#endif