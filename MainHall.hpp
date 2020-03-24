/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Header file for the MainHall class. Contains functions
**               to set the top, right, left, and bottom spaces for the
**               main hall, get the top space of the main hall, print
**               the room description, play the main hall's special 
**               event, and print a message if the event has already
**               been played.
***********************************************************************/

#ifndef MAIN_HALL_HPP
#define MAIN_HALL_HPP

#include "Space.hpp"

class MainHall: public Space
{
    private:
        bool guardDefeated;

    public:
        MainHall();

        virtual void setTop(Space *);
        virtual void setRight(Space *);
        virtual void setLeft(Space *);
        virtual void setBottom(Space *);

        virtual Space *getTop();

        virtual void roomDescription();
        virtual void event(Player *);
        virtual void eventAlreadyPlayed();
};

#endif