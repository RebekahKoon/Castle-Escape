/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Header file for the Tower class. Contains functions
**               to set the top, right, left, and bottom spaces for the
**               tower, print the room description, play the tower's
**               special event, and print a message if the event has 
**               already been played. Also contains a function that 
**               overrides the chooseItem function in the Space class to
**               allow the book of spells and key ring to be used.
***********************************************************************/

#ifndef TOWER_HPP
#define TOWER_HPP

#include "Space.hpp"

class Tower: public Space
{
    private:
        bool dragonDefeated;
        
    public:
        Tower();

        virtual void setTop(Space *);
        virtual void setRight(Space *);
        virtual void setLeft(Space *);
        virtual void setBottom(Space *);

        virtual void roomDescription();
        virtual void event(Player *);
        virtual void eventAlreadyPlayed();
        virtual void chooseItem(Player *);
};

#endif