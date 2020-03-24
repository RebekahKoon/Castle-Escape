/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Implementation file for the Tower class. Contains 
**               functions to set the top, right, left, and bottom 
**               spaces for the tower, print the room description, play 
**               the tower's special event, and print a message if the 
**               event has already been played. Also contains a function 
**               that overrides chooseItem function in the Space class 
**               to allow the book of spells and key ring to be used.
***********************************************************************/

#include "Tower.hpp"

/***********************************************************************
** Description: Default constructor for the Tower class. Inherits from
**              the Space class and sets member variables.
***********************************************************************/
Tower::Tower(): Space()
{
    //Menu option for Tower class's special event
    menuOption = "Fight the dragon";

    name = "tower";
    dragonDefeated = false;
}


/***********************************************************************
** Description: Void member function setTop takes in a pointer to a
**              Space object as a parameter. Calls setTop in the Space
**              class to assign the pointer to top.
**              Source: https://stackoverflow.com/questions/2089083/
**              pure-virtual-function-with-implementation
***********************************************************************/
void Tower::setTop(Space *topSpace)
{
    Space::setTop(topSpace);
}


/***********************************************************************
** Description: Void member function setRight takes in a pointer to a
**              Space object as a parameter. Calls setRight in the Space
**              class to assign the pointer to right.
***********************************************************************/
void Tower::setRight(Space *rightSpace)
{
    Space::setRight(rightSpace);
}


/***********************************************************************
** Description: Void member function setLeft takes in a pointer to a
**              Space object as a parameter. Calls setLeft in the Space
**              class to assign the pointer to left.
***********************************************************************/
void Tower::setLeft(Space *leftSpace)
{
    Space::setLeft(leftSpace);
}


/***********************************************************************
** Description: Void member function setBottom takes in a pointer to a
**              Space object as a parameter. Calls setBottom in the 
**              Space class to assign the pointer to bottom.
***********************************************************************/
void Tower::setBottom(Space *bottomSpace)
{
    Space::setBottom(bottomSpace);
}


/***********************************************************************
** Description: Void member function roomDescription prints out the
**              description of the room.
***********************************************************************/
void Tower::roomDescription()
{
    cout << "You sneak into the tower and climb to the top floor." << endl;
    cout << "A golden treasure chest is in the center of the room."  << endl;

    //Dragon is not defeated yet
    if (!dragonDefeated)
    {
        cout << "A dragon guards the treasure." << endl;
        cout << "You cannot get to the treasure without it noticing you." 
             << endl << endl;
    }

    //Dragon is defeated
    else
    {
        cout << "The dragon is still fast asleep." << endl << endl;
    }
}


/***********************************************************************
** Description: Void member function event takes a pointer to a Player
**              object as a parameter. If the player has the book of 
**              spells and the dragon has not been defeated, uses it to
**              defeat the dragon. If the dragon already defeated and
**              the user has a key, tells the user to use a key to open
**              the treasure chest.
***********************************************************************/
void Tower::event(Player *user)
{
    //User defeats the dragon if have the book of spells
    if (!dragonDefeated)
    {
        //Cannot defeat dragon if don't have book of spells
        if (!(user->haveBook()))
        {
            cout << "You do not have anything to defeat the dragon." << endl;
            cout << "It is best to stay hidden for now." << endl << endl;
        }

        //If have the book of spells
        else
        {
            cout << "You use the book of spells on the dragon!" << endl;
            cout << "The dragon falls into a deep sleep." << endl;
            cout << "You can now examine the treasure chest!" << endl << endl;

            dragonDefeated = true;

            //Dragon cannot be defeated again, so change menu option for event
            menuOption = "Check the treasure chest";
        }
    }

    //If dragon already defeated
    else
    {
        cout << "The dragon is still sleeping." << endl;
        cout << "You walk over and examine the treasure chest." << endl;
        cout << "You need to use a key to unlock it." << endl << endl;
    }
}


/***********************************************************************
** Description: Void member function eventAlreadyPlayed is used when
**              the event has already been played during the turn. If
**              the dragon has not yet been defeated, prints that the
**              player needs to find a way to defeat it. If the dragon
**              is defeated, prints that the dragon is still sleeping
**              and they need a key to open the chest.
***********************************************************************/
void Tower::eventAlreadyPlayed()
{
    //Cannot go to treasure chest if dragon not defeated
    if (!dragonDefeated)
    {
        cout << "You cannot do anything with the dragon in the way." << endl;
        cout << "You need to use an item to defeat him." << endl << endl;
    }

    //User can use key in inventory if dragon is sleeping
    else
    {
        cout << "The dragon won't be waking up soon." << endl;
        cout << "However, it looks like the treasure chest is locked." << endl;
        cout << "Use a key to open the chest." << endl << endl;
    }
    
}


/***********************************************************************
** Description: Void member function chooseItem takes in a pointer to a 
**              Player object as a parameter. If items are in the user's
**              inventory, has the user select an item to use. If book 
**              of spells is chosen and dragon is not defeated, defeats
**              dragon with book of spells. If dragon is defeated and
**              user chooses key ring, key ring is used to unlock the
**              treasure chest. Items that currently have no use will 
**              not be used. If no items in the inventory, prints a 
**              message saying that there are no items.
***********************************************************************/
void Tower::chooseItem(Player *user)
{
    string chosenItem;

    //If user has at least one item
    if (user->getNumItems() != 0)
    {
        //Selecting item from inventory to use
        chosenItem = user->useItem();

        //Using book of spells if dragon hasn't been defeated
        if ((chosenItem == "book of spells") && !dragonDefeated)
        {
            cout << "You use the book of spells on the dragon!" << endl;
            cout << "The dragon falls into a deep sleep." << endl;
            cout << "You can now examine the treasure chest!" << endl << endl;

            dragonDefeated = true;

            //Cannot defeat dragon again, so changing menu option
            menuOption = "Check the treasure chest";
        }

        //Can open chest if dragon is defeated
        else if (chosenItem == "key ring")
        {
            //Win the game if you can open the treasure chest
            if (dragonDefeated)
            {
                cout << "You find the key on the ring to unlock the chest."
                 << endl;
                cout << "You have successfully stolen the treasure!" << endl;
                cout << "You snatch the treasure and quickly exit the castle."
                     << endl << endl;

                won = true;
            }

            //Cannot open chest with dragon in the way
            else
            {
                cout << "The dragon is blocking your way." << endl;
                cout << "You can't get to the treasure chest." << endl << endl;
            }
            
        }
        
        //If an item is selected that cannot be used in this room
        else if (chosenItem != "food" && chosenItem != "guard uniform")
        {
            cout << "The " << chosenItem << " has no use right now." 
                 << endl << endl;
        }
    }
    
    //If user does not have any items
    else
    {
        cout << "You do not have any items in your inventory." << endl << endl;
    }
}