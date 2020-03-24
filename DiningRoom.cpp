/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Implementation file for the DiningRoom class. Contains 
**               functions to set the top, right, left, and bottom 
**               spaces for the dining room, print the room description,
**               play the dining room's special event, and print a
**               message if the event has already been played.
***********************************************************************/

#include "DiningRoom.hpp"

/***********************************************************************
** Description: Default constructor for the DiningRoom class. Inherits 
**              from the Space class and sets member variables.
***********************************************************************/
DiningRoom::DiningRoom(): Space()
{
    //Menu option for DiningRoom class's special event
    menuOption = "Steal from the guards";
    
    name = "dining room";
    keysStolen = false;
}


/***********************************************************************
** Description: Void member function setTop takes in a pointer to a
**              Space object as a parameter. Calls setTop in the Space
**              class to assign the pointer to top.
**              Source: https://stackoverflow.com/questions/2089083/
**              pure-virtual-function-with-implementation
***********************************************************************/
void DiningRoom::setTop(Space *topSpace)
{
    Space::setTop(topSpace);
}


/***********************************************************************
** Description: Void member function setRight takes in a pointer to a
**              Space object as a parameter. Calls setRight in the Space
**              class to assign the pointer to right.
***********************************************************************/
void DiningRoom::setRight(Space *rightSpace)
{
    Space::setRight(rightSpace);
}


/***********************************************************************
** Description: Void member function setLeft takes in a pointer to a
**              Space object as a parameter. Calls setLeft in the Space
**              class to assign the pointer to left.
***********************************************************************/
void DiningRoom::setLeft(Space *leftSpace)
{
    Space::setLeft(leftSpace);
}


/***********************************************************************
** Description: Void member function setBottom takes in a pointer to a
**              Space object as a parameter. Calls setBottom in the 
**              Space class to assign the pointer to bottom.
***********************************************************************/
void DiningRoom::setBottom(Space *bottomSpace)
{
    Space::setBottom(bottomSpace);
}


/***********************************************************************
** Description: Void member function roomDescription prints out the
**              description of the room.
***********************************************************************/
void DiningRoom::roomDescription()
{
    cout << "You peek into the dining room. A big feast is happening today."
         << endl;

    cout << "It is packed with guards!" << endl << endl;

    //Prints if key ring has not been stolen yet
    if (!keysStolen)
    {
        cout << "You see a ring of keys on one guard's belt." << endl;
        cout << "One of these keys must be for the treasure." << endl;
        cout << "Maybe you can steal it!" << endl << endl;
    }

    //If key rings was stolen
    else
    {
        cout << "You have already stolen the keys." << endl;
        cout << "However, stealing some food might be useful." << endl << endl;
    }
    
}


/***********************************************************************
** Description: Void member function event takes a pointer to a Player
**              object as a parameter. Player can choose whether or not
**              they want to steal an item from the guard. If they want
**              to steal, determines whether the item was stolen using
**              the player's percent chance of stealing an item. Item is
**              added to the inventory if stolen. If not stolen, guards
**              notice the player and step amount is decreased.
***********************************************************************/
void DiningRoom::event(Player *user)
{
        int choice,
            steal,
            stealChance = user->getStealChance();  //User's chance to steal

        const int MAX_STEAL_CHANCE = 100,
                  YES = 1,
                  NO = 2;

        string stolenItem;

        //If player has not gotten the key ring yet
        if (!keysStolen)
        {
            stolenItem = "key ring";

            cout << "Do you want to try stealing the keys?" << endl;
        }

        //Can steal food if key ring has been stolen
        else if (keysStolen)
        {
            stolenItem = "food";

            cout << "You already stole the keys." << endl;
            cout << "Do you want to try stealing some food?" << endl;
        }

        cout << "You have a " << stealChance
             << "% chance of stealing them." << endl << endl;

        //Not guaranteed that item will be stolen if steal chance isn't 100
        if (stealChance != MAX_STEAL_CHANCE)
        {
            cout << "If caught, the guards will be on high alert, " << endl
                 << "which will decrease the steps you can take." << endl;

            cout << "Maybe you can find a way to increase your stealth."
                 << endl;

            cout << "Do you want to try stealing it anyway?" << endl << endl;
        }

        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Enter your choice (1-2): ";
        choice = validInput(YES, NO);

        cout << endl;

        //Trying to steal an item
        if (choice == YES)
        {
            steal = rand() % 100 + 1;

            //If item is be stolen
            if (steal <= stealChance)
            {
                cout << "You snuck in and successfully stole the "
                     << stolenItem << "!" << endl << endl;

                //Adding stolen item to inventory
                user->addItem(stolenItem);

                keysStolen = true;
            }

            //If not stolen, lose steps after guard notices you
            else
            {
                int loseStepAmount = 10;

                cout << "The guards noticed you!" << endl;
                cout << "The castle is on high alert." << endl;
                cout << "You lost " << loseStepAmount << " steps." << endl;

                //Decreasing steps
                user->decreaseSteps(loseStepAmount);

                cout << "You now have " << user->getSteps() 
                     << " steps before you are caught." << endl << endl;
            }
        }

        //Deciding not to steal item
        else
        {
            cout << "You decide not to risk stealing anything." << endl;
            cout << "You should leave before you are seen." << endl << endl;
        }
}


/***********************************************************************
** Description: Void member function eventAlreadyPlayed is used when
**              the event function has already played during the turn.
**              Tells the player that it is too risky to steal something
**              else right now and they should try again later.
***********************************************************************/
void DiningRoom::eventAlreadyPlayed()
{
    cout << "You have spent too much time here!" << endl;
    cout << "If you stay here much longer, you may get spotted." << endl;
    cout << "Try coming back later." << endl << endl;
}
