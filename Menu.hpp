/**********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Header file for the Menu class. Contains functions
**               that give user the option to play the game, choose an
**               action to perform in the game, move to a new space,
**               and play the game again.
**********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "validInput.hpp"

#include <iostream>

using std::cout;
using std::endl;

//Used to determine if user wants to play.
enum PlayOptions {YES = 1, NO};

class Menu
{
    public:
        int chooseToPlay();
        int chooseAction(string menuOption);
        int chooseNewSpace();
        int playAgain();
};

#endif