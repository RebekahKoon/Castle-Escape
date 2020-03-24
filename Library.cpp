/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Implementation file for the Library class. Contains 
**               functions to set the top, right, left, and bottom 
**               spaces for the library, print the room description, 
**               play the library's special event, and print a message 
**               if the event has already been played. Also contains a 
**               function that overrides chooseItem function in the 
**               Space class to allow library map to be used.
***********************************************************************/

#include "Library.hpp"

/***********************************************************************
** Description: Default constructor for the Library class. Inherits 
**              from the Space class and sets member variables.
***********************************************************************/
Library::Library(): Space()
{
    //Menu option for Library class's special event
    menuOption = "Go to the reading area";
    name = "library";

    //Used to determine if player already visited the secret bookshelf
    foundBook = false;
}


/***********************************************************************
** Description: Void member function setTop takes in a pointer to a
**              Space object as a parameter. Calls setTop in the Space
**              class to assign the pointer to top.
**              Source: https://stackoverflow.com/questions/2089083/
**              pure-virtual-function-with-implementation
***********************************************************************/
void Library::setTop(Space *topSpace)
{
    Space::setTop(topSpace);
}


/***********************************************************************
** Description: Void member function setRight takes in a pointer to a
**              Space object as a parameter. Calls setRight in the Space
**              class to assign the pointer to right.
***********************************************************************/
void Library::setRight(Space *rightSpace)
{
    Space::setRight(rightSpace);
}


/***********************************************************************
** Description: Void member function setLeft takes in a pointer to a
**              Space object as a parameter. Calls setLeft in the Space
**              class to assign the pointer to left.
***********************************************************************/
void Library::setLeft(Space *leftSpace)
{
    Space::setLeft(leftSpace);
}


/***********************************************************************
** Description: Void member function setBottom takes in a pointer to a
**              Space object as a parameter. Calls setBottom in the 
**              Space class to assign the pointer to bottom.
***********************************************************************/
void Library::setBottom(Space *bottomSpace)
{
    Space::setBottom(bottomSpace);
}


/***********************************************************************
** Description: Void member function roomDescription prints out the
**              description of the room.
***********************************************************************/
void Library::roomDescription()
{
    cout << "You snuck into the library." << endl;
    cout << "Hundreds of bookshelves line the walls." << endl;

    //Message prints if book hasn't been found
    if (!foundBook)
    {
        cout << "This place is so big that it must contain a secret." << endl;
        cout << "Maybe you can discover something using an item." 
             << endl << endl;
    }
}


/***********************************************************************
** Description: Void member function takes in a pointer to a Player
**              object as a parameter. Plays a random event in which
**              the player either gets spotted by someone in the library
**              and loses steps, discovers a book that increases the
**              number of steps they can take, or discovers a book that
**              increases their chance of stealing an item.
***********************************************************************/
void Library::event(Player *user)
{
    int event = rand() % 3 + 1;

    //Player gets caught; decrease steps
    if (event == GET_CAUGHT)
    {
        int stepsLost = 5;

        cout << "A person reading a book spotted you!" << endl;
        cout << "They ran off to alert the guards." << endl;

        user->decreaseSteps(stepsLost);
        cout << "The steps you can take before being caught is now "
             << user->getSteps() << "." << endl << endl;
    }

    //Player finds useful book; increases steps
    else if (event == INCREASE_STEPS)
    {
        int stepsGained = 5;

        cout << "You decided to pick up a book and read a chapter." << endl;
        cout << "You discovered useful information about the castle!" << endl;
        cout << "This will help you sneak around." << endl << endl;

        //Updating number of steps
        user->increaseSteps(stepsGained);
        cout << "The steps you can take before being caught is now "
             << user->getSteps() << "." << endl
             << endl;
    }

    //Player finds useful book; increases steal chance
    else if (event == INCREASE_STEAL)
    {
        int stealChanceAdded = 5;

        cout << "You decided to pick up a book and read a chapter." << endl;
        cout << "It was a book about a famous thief." << endl;
        cout << "You gained some valuable information!" << endl;

        //User cannot have steal chance greater than 100
        if (user->getStealChance() == 100)
        {
            cout << "Your steal chance was already maxed out!" << endl;
            cout << "You can steal any item with ease." << endl << endl;
        }

        //If steal chance not maxed out yet
        else
        {
            //Updating steal chance
            user->increaseStealChance(stealChanceAdded);
            
            cout << "Your steal chance is now " 
                 << user->getStealChance() << "%." << endl << endl;
        }
    }

    //Message for player to use library map if haven't been to secret shelf
    if (!foundBook)
    {
        cout << "There must be a secret in here somewhere." << endl;
        cout << "An item may help you find the secret." << endl << endl;
    }

    //If player already visited secret shelf
    else
    {
        cout << "You already looked at the hidden bookshelf." << endl;
        cout << "The book of spells will be useful in the future." 
             << endl << endl;
    }
}

/***********************************************************************
** Description: Void member function eventAlreadyPlayed is used when
**              the event function has already played during the turn. 
**              Tells the player that it is too risky to go to the 
**              reading area again and they should try again later.
***********************************************************************/
void Library::eventAlreadyPlayed()
{   
    cout << "It may not be a good idea to back to the reading area." << endl;
    cout << "You don't want to draw too much attention to yourself." << endl;

    //Reminding player to use library map to find book of spells
    if (!foundBook)
    {
        cout << "However, there may be something useful in here." << endl;
        cout << "Perhaps an item will help you discover a secret." 
             << endl << endl;
    }

    //If already found secret shelf
    else
    {
        cout << "Try coming back later." << endl << endl;
    }
}


/***********************************************************************
** Description: Void member function chooseItem takes in a pointer to a 
**              Player object as a parameter. If items are in the user's
**              inventory, has the user select an item to use. Items
**              that currently have no use will not be used. If library
**              map is used, user gets book of spells. If no items in
**              the inventory, prints a message saying that there are
**              no items.
***********************************************************************/
void Library::chooseItem(Player *user)
{
    string chosenItem,
            map = "library map";

    //If user has at least one item
    if (user->getNumItems() != 0)
    {
        //Selecting item from inventory to use
        chosenItem = user->useItem();

        //Find book of spells if select library map when haven't been to shelf
        if (chosenItem == map && !foundBook)
        {
            string foundItem = "book of spells";

            cout << "You go to the bookshelf marked on the map." << endl;
            cout << "You find a book of spells on the shelf." << endl;
            cout << "Maybe you can use this later!" << endl << endl;

            //Adding book of spells to inventory
            user->addItem(foundItem);
            
            foundBook = true;
        }

        //If already have the book of spells
        else if (chosenItem == map && foundBook)
        {
            cout << "You already investigated the marked bookshelf." << endl;
            cout << "There is nothing else marked on the map." << endl << endl;
        }

        //If an item is selected that cannot be used in this room
        else if (chosenItem != "food" && chosenItem != "guard uniform")
        {
            cout << "The " << chosenItem << " has no use right now." 
                 << endl << endl;
        }
    }

    //If user has no items
    else
    {
        cout << "You do not have any items in your inventory." << endl << endl;
    }  
}