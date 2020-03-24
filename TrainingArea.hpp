/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Header file for the TrainingArea class. Has functions
**               to set the top, right, left, and bottom spaces for the
**               training area, print the room description, play the 
**               training area's special event, and print a message if
**               the event has already been played. 
***********************************************************************/

#ifndef TRAINING_AREA_HPP
#define TRAINING_AREA_HPP

#include "Space.hpp"

//Used to determine what training the user wants to do
enum TrainingOptions {AGILITY = 1, STEALING};

class TrainingArea: public Space
{
    private:
        bool foundUniform;

    public:
        TrainingArea();

        virtual void setTop(Space *);
        virtual void setRight(Space *);
        virtual void setLeft(Space *);
        virtual void setBottom(Space *);

        virtual void roomDescription();
        virtual void event(Player *);
        virtual void eventAlreadyPlayed();
};

#endif