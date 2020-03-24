/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Implementation file for the Courtyard class. Contains 
**               functions to set the top, right, left, and bottom 
**               spaces for the courtyard, get the top space of the 
**               courtyard, print the room description, play the
**               courtyard's special event, and print a message if the
**               event has already been played.
***********************************************************************/

#include "Courtyard.hpp"

/***********************************************************************
** Description: Default constructor for the Courtyard class. Inherits
**              from the Space class and sets member variables.
***********************************************************************/
Courtyard::Courtyard(): Space()
{
    //Menu option for Courtyard class's special event
    menuOption = "Pull the lever";
    
    name = "courtyard";
    drawbridgeDown = false;
    foundFood = false;
}


/***********************************************************************
** Description: Void member function setTop takes in a pointer to a
**              Space object as a parameter. Calls setTop in the Space
**              class to assign the pointer to top.
**              Source: https://stackoverflow.com/questions/2089083/
**              pure-virtual-function-with-implementation
***********************************************************************/
void Courtyard::setTop(Space *topSpace)
{
    Space::setTop(topSpace);
}


/***********************************************************************
** Description: Void member function setRight takes in a pointer to a
**              Space object as a parameter. Calls setRight in the Space
**              class to assign the pointer to right.
***********************************************************************/
void Courtyard::setRight(Space *rightSpace)
{
    Space::setRight(rightSpace);
}


/***********************************************************************
** Description: Void member function setLeft takes in a pointer to a
**              Space object as a parameter. Calls setLeft in the Space
**              class to assign the pointer to left.
***********************************************************************/
void Courtyard::setLeft(Space *leftSpace)
{
    Space::setLeft(leftSpace);
}


/***********************************************************************
** Description: Void member function setBottom takes in a pointer to a
**              Space object as a parameter. Calls setBottom in the 
**              Space class to assign the pointer to bottom.
***********************************************************************/
void Courtyard::setBottom(Space *bottomSpace)
{
    Space::setBottom(bottomSpace);
}


/***********************************************************************
** Description: Member function getTop returns a pointer. If the 
**              the drawbridge has not been lowered, returns null. If
**              it has been lowered, returns pointer to Space object
**              assigned to top.
***********************************************************************/
Space *Courtyard::getTop()
{
    //Cannot move forward if drawbridge not down yet
    if(!drawbridgeDown)
    {
        cout << "The drawbridge has not been lowered yet." << endl
             << "To move forward, you need to lower it." << endl << endl;
        
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
void Courtyard::roomDescription()
{
    cout << "You arrive in the courtyard." << endl;
    cout << "A drawbridge leading to the tower is up ahead." << endl;
    cout << "It looks like there is a lever that controls it." << endl;
    
    if (drawbridgeDown)
    {
        cout << "However, the drawbridge is already lowered." << endl << endl;
    }

    else
    {
        cout << "The lever should lower the drawbridge." << endl << endl;
    }
}


/***********************************************************************
** Description: Void member function event takes a pointer to a Player
**              object as a parameter. Raises the drawbridge if it is
**              down or lowers the drawbridge if it is up. If the area
**              has not yet been visited, user finds food that they add
**              to their inventory.
***********************************************************************/
void Courtyard::event(Player *user)
{
    //Pulling lever to lower drawbridge
    if (!drawbridgeDown)
    {
        cout << "You pull the lever." << endl;
        cout << "It lowers the drawbridge!" << endl << endl;
        drawbridgeDown = true;

        //Find food if haven't visited yet
        if (!foundFood)
        {
            string foundItem = "food";

            cout << "You found " << foundItem << " on a bench nearby." << endl;

            cout << "If you eat it, you will feel more focused, " << endl
             << "making it more difficult to be captured and" << endl
             << "increasing the steps you can take by 5." << endl << endl;

            //Adding food to inventory
            user->addItem(foundItem);

            //Cannot find again
            foundFood = true;
        }
    }

    //Pulling lever to raise drawbridge
    else
    {
        cout << "You pull the lever." << endl;
        cout << "The drawbridge was raised." << endl;
        cout << "You need to pull the lever again to reach the tower."
             << endl << endl;
             
        drawbridgeDown = false;
    }
}


/***********************************************************************
** Description: Void member function eventAlreadyPlayed is used when
**              the event function has already played during the turn. 
**              If the drawbridge is up, lowers the drawbridge. If it is
**              down, asks player if they want to pull the lever again
**              to raise it. Raises if they select yes or keeps it 
**              lowered if they select no.
***********************************************************************/
void Courtyard::eventAlreadyPlayed()
{
    //Lowering the drawbridge
    if (!drawbridgeDown)
    {
        cout << "You pull the lever." << endl;
        cout << "It lowers the drawbridge!" << endl << endl;
        drawbridgeDown = true;
    }

    //Can raise drawbridge if it is lowered
    else
    {
        int choice;
        const int YES = 1,
                  NO = 2;
        
        cout << "You already pulled the lever to lower the drawbridge."
             << endl;
        cout << "Do you really want to pull it again?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Enter your choice (1-2): ";
        choice = validInput(YES, NO);

        cout << endl;

        //Raising drawbridge
        if (choice == YES)
        {
            cout << "You pull the lever." << endl;
            cout << "The drawbridge was raised." << endl;
            cout << "You need to pull the lever again to reach the tower."
                 << endl << endl;
            
            drawbridgeDown = false;
        }

        //Deciding not to raise drawbridge
        else
        {
            cout << "You decide not to pull the lever." << endl << endl;
        }
    }
}