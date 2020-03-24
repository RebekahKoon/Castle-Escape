/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Header file for the Courtyard class. Contains functions
**               to set the top, right, left, and bottom spaces for the
**               courtyard, get the top space of the courtyard, print
**               the room description, play the courtyard's special 
**               event, and print a message if the event has already
**               been played.
***********************************************************************/

#ifndef COURTYARD_HPP
#define COURTYARD_HPP

#include "Space.hpp"

class Courtyard: public Space
{
    protected:
        bool drawbridgeDown;
        bool foundFood;
        
    public:
        Courtyard();

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