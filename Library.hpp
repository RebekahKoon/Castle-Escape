/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Header file for the Library class. Contains functions
**               to set the top, right, left, and bottom spaces for the
**               library, print the room description, play the library's
**               special event, and print a message if the event has 
**               already been played. Also contains a function that 
**               overrides the chooseItem function in the Space class to
**               allow the library map to be used.
***********************************************************************/

#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Space.hpp"

//enum for playing random event
enum RandomEvent {GET_CAUGHT = 1, INCREASE_STEPS, INCREASE_STEAL};

class Library: public Space
{
    private:
        bool foundBook;
    public:
        Library();

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