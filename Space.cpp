/************************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Implementation file for the Space class. Creates a space
**               that the user can interact with. Has functions to set
**               the top, right, left, and bottom spaces adjacent to
**               the current space, get the adjacent top, right, left,
**               and bottom spaces, get the space's name, get the menu
**               option for the current space's special action, determine
**               if the game has been won, print the room description, 
**               play an event, and choose an item to use.
************************************************************************/

#include "Space.hpp"

/***********************************************************************
** Description: Default constructor for the Space class, which sets the
**              member variables for the Space class.
***********************************************************************/
Space::Space()
{
    //Sets the four directions the player can move in to null
    top = NULL;
    right = NULL;
    left = NULL;
    bottom = NULL;

    menuOption = "Survey the area";
    name = "";
    won = false;
}


/***********************************************************************
** Description: Void member function setTop takes in a pointer to a
**              Space object as a parameter. Uses the pointer to set the
**              space above the current space.
***********************************************************************/
void Space::setTop(Space *topIn)
{
    top = topIn;
}


/***********************************************************************
** Description: Void member function setRight takes in a pointer to a
**              Space object as a parameter. Uses the pointer to set the 
**              space to the right of the current space.
***********************************************************************/
void Space::setRight(Space *rightIn)
{
    right = rightIn;
}


/***********************************************************************
** Description: Void member function setLeft takes in a pointer to a
**              Space object as a parameter. Uses the pointer to set the 
**              space to the left of the current space.
***********************************************************************/
void Space::setLeft(Space *leftIn)
{
    left = leftIn;
}


/***********************************************************************
** Description: Void member function setBottom takes in a pointer to a
**              Space object as a parameter. Uses the pointer to set the 
**              space below the current space.
***********************************************************************/
void Space::setBottom(Space *bottomIn)
{
    bottom = bottomIn;
}


/***********************************************************************
** Description: Member function getTop returns a pointer to the space 
**              in front of the current space. If the pointer points to
**              null also prints that there is nothing ahead.
***********************************************************************/
Space *Space::getTop()
{
    //If no space ahead
    if (top == NULL)
    {
        cout << "There is nothing up ahead." << endl << endl;
    }

    return top;
}


/***********************************************************************
** Description: Member function getRight returns a pointer to the space 
**              to the right of the current space. If the pointer points
**              to null, also prints that there is nothing to the right.
***********************************************************************/
Space *Space::getRight()
{
    //If no space to the right
    if (right == NULL)
    {
        cout << "There is nothing to the right." << endl << endl;
    }

    return right;
}


/***********************************************************************
** Description: Member function getLeft returns a pointer to the space 
**              to the left of the current space. If the pointer points
**              to null, also prints that there is nothing to the left.
***********************************************************************/
Space *Space::getLeft()
{
    //If no space to the left
    if (left == NULL)
    {
        cout << "There is nothing to the left." << endl << endl;
    }

    return left;
}


/***********************************************************************
** Description: Member function getBottom returns a pointer to the space 
**              behind the current space.  If pointer points to null,
**              also prints that there is nothing behind the player.
***********************************************************************/
Space *Space::getBottom()
{
    //If no space down
    if (bottom == NULL)
    {
        cout << "There is nowhere to go behind you." << endl << endl;
    }

    return bottom;
}


/***********************************************************************
** Description: Member function getName returns the space's name.
***********************************************************************/
string Space::getName()
{
    return name;
}


/***********************************************************************
** Description: Member function getMenuOption returns the space's menu
**              option for its special action.
***********************************************************************/
string Space::getMenuOption()
{
    return menuOption;
}


/***********************************************************************
** Description: Member function gameWon returns true if the game has
**              been won or false if it has not been won yet.
***********************************************************************/
bool Space::gameWon()
{
    return won;
}


/***********************************************************************
** Description: Void member function chooseItem takes in a pointer to a 
**              Player object as a parameter. If items are in the user's
**              inventory, has the user select an item to use. Items
**              that currently have no use will not be used. If no items
**              are in the inventory, prints a message saying that there
**              are no items.
***********************************************************************/
void Space::chooseItem(Player *user)
{
    string chosenItem;

    //Selecting an item if inventory not empty
    if (user->getNumItems() != 0)
    {
        chosenItem = user->useItem();

        if (chosenItem != "food" && chosenItem != "guard uniform")
        {
            cout << "The " << chosenItem << " has no use right now." 
                 << endl << endl;
        }
    }
    
    //If inventory empty
    else
    {
        cout << "You do not have any items in your inventory." << endl << endl;
    }
}


/***********************************************************************
** Description: Destructor for the Space class.
***********************************************************************/
Space::~Space()
{
}