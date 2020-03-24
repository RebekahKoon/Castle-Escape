/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Header file for the Kitchen class. Contains functions
**               to set the top, right, left, and bottom spaces for the
**               kitchen, print the room description, play the kitchen's
**               special event, and print a message if the event has
**               already been played. 
***********************************************************************/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "Space.hpp"

class Kitchen: public Space
{
    public:
        Kitchen();

        virtual void setTop(Space *);
        virtual void setRight(Space *);
        virtual void setLeft(Space *);
        virtual void setBottom(Space *);

        virtual void roomDescription();
        virtual void event(Player *);
        virtual void eventAlreadyPlayed();
};

#endif