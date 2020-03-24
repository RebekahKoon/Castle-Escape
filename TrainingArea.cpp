/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Implementation file for the TrainingArea class. Has
**               functions to set the top, right, left, and bottom 
**               spaces for the training area, print the description of
**               the room, play the training area's special event, and
**               print a message if the event has already been played.
***********************************************************************/

#include "TrainingArea.hpp"

/***********************************************************************
** Description: Default constructor for the TrainingArea class. Inherits
**              from the Space class and sets member variables.
***********************************************************************/
TrainingArea::TrainingArea(): Space()
{
    //Menu option for TrainingArea class's special event
    menuOption = "Explore the area";
    
    name = "training area";
    foundUniform = false;
}


/***********************************************************************
** Description: Void member function setTop takes in a pointer to a
**              Space object as a parameter. Calls setTop in the Space
**              class to assign the pointer to top.
**              Source: https://stackoverflow.com/questions/2089083/
**              pure-virtual-function-with-implementation
***********************************************************************/
void TrainingArea::setTop(Space *topSpace)
{
    Space::setTop(topSpace);
}


/***********************************************************************
** Description: Void member function setRight takes in a pointer to a
**              Space object as a parameter. Calls setRight in the Space
**              class to assign the pointer to right.
***********************************************************************/
void TrainingArea::setRight(Space *rightSpace)
{
    Space::setRight(rightSpace);
}


/***********************************************************************
** Description: Void member function setLeft takes in a pointer to a
**              Space object as a parameter. Calls setLeft in the Space
**              class to assign the pointer to left.
***********************************************************************/
void TrainingArea::setLeft(Space *leftSpace)
{
    Space::setLeft(leftSpace);
}


/***********************************************************************
** Description: Void member function setBottom takes in a pointer to a
**              Space object as a parameter. Calls setBottom in the 
**              Space class to assign the pointer to bottom.
***********************************************************************/
void TrainingArea::setBottom(Space *bottomSpace)
{
    Space::setBottom(bottomSpace);
}


/***********************************************************************
** Description: Void member function roomDescription prints out the
**              description of the room.
***********************************************************************/
void TrainingArea::roomDescription()
{
    cout << "You sneak into the training grounds for the guards." << endl;
    cout << "No one is around at the moment." << endl;
    cout << "All of the guards seem to be in the castle." << endl << endl;
}


/***********************************************************************
** Description: Void member function event takes a pointer to a Player
**              object as a parameter. If guard uniform has not been 
**              found, adds to inventory. Asks user if they want to 
**              train in agility or stealing abilities. If they choose
**              agility, user's steps increases by 5. If they choose
**              stealing ability, increases steal chance by 10.
***********************************************************************/
void TrainingArea::event(Player *user)
{
    int choice;

    const int MIN_CHOICE = 1,
              MAX_CHOICE = 2;

    //Find guard uniform if haven't visited yet
    if (!foundUniform)
    {
        string foundItem = "guard uniform";

        cout << "You notice a guard's uniform that was left behind." << endl;
        cout << "If worn, you will be less noticeable when stealing items."
             << endl << endl;

        //Adding guard uniform to inventory
        user->addItem(foundItem);

        foundUniform = true;

        //Changing menu option for this space
        menuOption = "Do some training";
    }

    //Choosing what type of training to do
    cout << "You decide to do some training while you're here." << endl;
    cout << "What would you like to do?" << endl << endl;
    cout << "1. Agility training (increases steps)" << endl;
    cout << "2. Practice stealing items (increases steal chance)" << endl;
    cout << "Enter your choice (1-2): ";
    choice = validInput(MIN_CHOICE, MAX_CHOICE);

    cout << endl;

    //Do agility training
    if (choice == AGILITY)
    {
        int numStepsAdded = 5;

        cout << "You do some agility training exercises." << endl;
        cout << "You feel more confident sneaking around the castle!" << endl;

        //Updating step amount
        user->increaseSteps(numStepsAdded);

        cout << "The steps you can take before being caught increased to " 
             << user->getSteps() << "." << endl << endl;
    }

    //Practice stealing items
    else if (choice == STEALING)
    {
        int stealChanceAdded = 10;

        cout << "You work on your stealth for stealing items." << endl;

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

            cout << "Your chance of stealing an item is now " 
                << user->getStealChance() << "%." << endl << endl;
        }
    }
}


/***********************************************************************
** Description: Void member function eventAlreadyPlayed is used when
**              the event has already been played during the turn. 
**              Prints that player is tired and needs to wait before 
**              doing any more training.
***********************************************************************/
void TrainingArea::eventAlreadyPlayed()
{
    cout << "You are feeling tired from your training." << endl;
    cout << "Come back again to train after taking a break." << endl << endl;
}