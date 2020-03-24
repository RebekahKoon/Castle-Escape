/************************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Header file for the DiningRoom class. Contains functions
**               to set the top, right, left, and bottom spaces for the
**               dining room, print the room description, play the dining
**               room's special event, and print a message if the event
**               has already been played. 
************************************************************************/

#ifndef DINING_ROOM_HPP
#define DINING_ROOM_HPP

#include "Space.hpp"

#include <cstdlib>
#include <ctime>

class DiningRoom: public Space
{
    private:
        bool keysStolen;
        
    public:
        DiningRoom();

        virtual void setTop(Space *);
        virtual void setRight(Space *);
        virtual void setLeft(Space *);
        virtual void setBottom(Space *);

        virtual void roomDescription();
        virtual void event(Player *);
        virtual void eventAlreadyPlayed();
};

#endif