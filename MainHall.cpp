/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Implementation file for the MainHall class. Contains 
**               functions to set the top, right, left, and bottom 
**               spaces for the main hall, get the top space of the 
**               main hall, print the room description, play the main 
**               hall's special event, and print a message if the event
**               has already been played.
***********************************************************************/

#include "MainHall.hpp"


/***********************************************************************
** Description: Default constructor for the MainHall class. Inherits 
**              from the Space class and sets member variables.
***********************************************************************/
MainHall::MainHall(): Space()
{
    //Menu option for MainHall class's special event
    menuOption = "Defeat the guard";

    name = "main hall";

    guardDefeated = false;
}


/***********************************************************************
** Description: Void member function setTop takes in a pointer to a
**              Space object as a parameter. Calls setTop in the Space
**              class to assign the pointer to top.
**              Source: https://stackoverflow.com/questions/2089083/
**              pure-virtual-function-with-implementation
***********************************************************************/
void MainHall::setTop(Space *topSpace)
{
    Space::setTop(topSpace);
}


/***********************************************************************
** Description: Void member function setRight takes in a pointer to a
**              Space object as a parameter. Calls setRight in the Space
**              class to assign the pointer to right.
***********************************************************************/
void MainHall::setRight(Space *rightSpace)
{
    Space::setRight(rightSpace);
}


/***********************************************************************
** Description: Void member function setLeft takes in a pointer to a
**              Space object as a parameter. Calls setLeft in the Space
**              class to assign the pointer to left.
***********************************************************************/
void MainHall::setLeft(Space *leftSpace)
{
    Space::setLeft(leftSpace);
}


/***********************************************************************
** Description: Void member function setBottom takes in a pointer to a
**              Space object as a parameter. Calls setBottom in the 
**              Space class to assign the pointer to bottom.
***********************************************************************/
void MainHall::setBottom(Space *bottomSpace)
{
    Space::setBottom(bottomSpace);
}


/***********************************************************************
** Description: Member function getTop returns a pointer to a Space 
**              object. If the guard hasn't been defeated yet, user 
**              cannot go forward, so returns null. If the guard has 
**              been defeated, returns the pointer to top.
***********************************************************************/
Space *MainHall::getTop()
{
    //Cannot move to courtyard if guard is still in main hall
    if(!guardDefeated)
    {
        cout << "A guard is blocking the way." << endl;
        cout << "You need to defeat the guard before "
             << "going to the courtyard." << endl << endl;
        
        return NULL;
    }

    else
    {
        return top;
    }
    
}


/***********************************************************************
** Description: Void member function roomDescription prints out the
**              description of the room.
***********************************************************************/
void MainHall::roomDescription()
{
    cout << "You hide behind a suit of armor in the main hall." 
         << endl << endl;

    //Prints if guard has not been defeated
    if(!guardDefeated)
    {
        cout << "A guard is blocking the way to the courtyard!" << endl;
        cout << "You decide to stay out of his sight." << endl << endl;
    }
}


/***********************************************************************
** Description: Void member function event takes in a pointer to a 
**              Player object as a parameter. The user knocks out the
**              guard and steals his library map. Puts library map in
**              the user's inventory. If guard has already been knocked
**              out, prints that the guard is still unconscious.
***********************************************************************/
void MainHall::event(Player *user)
{
    int choice;

    const int YES = 1,
              NO = 2;
    string libraryMap = "library map";

    //Defeating the guard if not defeated yet
    if (!guardDefeated)
    {
        string stolenItem = "library map";

        cout << "You snuck behind the guard and knocked him out!" << endl;

        guardDefeated = true;

        //Stealing library map
        cout << "You swiped his " << stolenItem << "." << endl;
        cout << "A mark has been made by one of the bookshelves." << endl;
        cout << "Use the map in the library to investigate this shelf!" 
            << endl << endl;

        //Adding library map to inventory
        user->addItem(stolenItem);

        //Guard is defeated, so cannot defeat if event is picked again
        menuOption = "Check on the guard";
    }

    //If guard has already been defeated
    else
    {
        cout << "The guard is still unconscious." << endl;
        cout << "He won't be waking up soon." << endl << endl;
    }
}


/***********************************************************************
** Description: Void member function eventAlreadyPlayed prints a message
**              if the user already performed the event during the turn.
***********************************************************************/
void MainHall::eventAlreadyPlayed()
{
    cout << "The guard is still unconscious." << endl;
    cout << "He won't be waking up soon." << endl << endl;
}