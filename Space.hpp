/************************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Header file for the Space class. Creates a space that 
**               the user can interact with. Contains functions to set
**               the top, right, left, and bottom spaces adjacent to the
**               current space, get the adjacent top, right, left, and
**               bottom spaces, get the space's name, get the menu option
**               for the current space's special action, determine if the
**               game has been won, print the room description, play an
**               event, and choose an item to use.
************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "validInput.hpp"
#include "Player.hpp"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Space
{
    protected:
        Space *top;
        Space *right;
        Space *left;
        Space *bottom;

        string menuOption;
        string name;
        bool won;

    public:
        Space();

        virtual void setTop(Space *) = 0;
        virtual void setRight(Space *) = 0;
        virtual void setLeft(Space *) = 0;
        virtual void setBottom(Space *) = 0;

        virtual Space *getTop();
        virtual Space *getRight();
        virtual Space *getLeft();
        virtual Space *getBottom();

        virtual string getName();
        virtual string getMenuOption();
        virtual bool gameWon();
        
        virtual void roomDescription() = 0;
        virtual void event(Player *) = 0;
        virtual void eventAlreadyPlayed() = 0;

        virtual void chooseItem(Player *);

        virtual ~Space();
};

#endif