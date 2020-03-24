/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Implementation file for the Kitchen class. Contains 
**               functions to set the top, right, left, and bottom 
**               spaces for the kitchen, print the room description, 
**               play the kitchen's special event, and print a message 
**               if the event has already been played.
***********************************************************************/

#include "Kitchen.hpp"


/***********************************************************************
** Description: Default constructor for the Kitchen class. Inherits from
**              the Space class and sets member variables.
***********************************************************************/
Kitchen::Kitchen(): Space()
{
    //Menu option for Kitchen class's special event
    menuOption = "Search for food";
    
    name = "kitchen";
}


/***********************************************************************
** Description: Void member function setTop takes in a pointer to a
**              Space object as a parameter. Calls setTop in the Space
**              class to assign the pointer to top.
**              Source: https://stackoverflow.com/questions/2089083/
**              pure-virtual-function-with-implementation
***********************************************************************/
void Kitchen::setTop(Space *topSpace)
{
    Space::setTop(topSpace);
}


/***********************************************************************
** Description: Void member function setRight takes in a pointer to a
**              Space object as a parameter. Calls setRight in the Space
**              class to assign the pointer to right.
***********************************************************************/
void Kitchen::setRight(Space *rightSpace)
{
    Space::setRight(rightSpace);
}


/***********************************************************************
** Description: Void member function setLeft takes in a pointer to a
**              Space object as a parameter. Calls setLeft in the Space
**              class to assign the pointer to left.
***********************************************************************/
void Kitchen::setLeft(Space *leftSpace)
{
    Space::setLeft(leftSpace);
}


/***********************************************************************
** Description: Void member function setBottom takes in a pointer to a
**              Space object as a parameter. Calls setBottom in the 
**              Space class to assign the pointer to bottom.
***********************************************************************/
void Kitchen::setBottom(Space *bottomSpace)
{
    Space::setBottom(bottomSpace);
}


/***********************************************************************
** Description: Void member function roomDescription prints out the
**              description of the room.
***********************************************************************/
void Kitchen::roomDescription()
{
    cout << "You stay in the shadows and sneak into the kitchen." << endl;
    cout << "Chefs are busy preparing for today's feast." << endl << endl;
}


/***********************************************************************
** Description: Void member function event takes a pointer to a Player
**              object as a parameter. Asks the player if they want to 
**              try stealing some food. If they want to try, a random
**              number is generated to determine if they successfully
**              stole the food. Adds the food to the user's inventory.
***********************************************************************/
void Kitchen::event(Player *user)
{
    int choice,
        stealChance;
    const int YES = 1,
              NO = 2;

        string item = "food";

    //Determing user's percent chance to steal food
    stealChance = user->getStealChance();

    cout << "Huge amounts of food are on the counter for the feast." << endl;
    cout << "You have a " << stealChance << "% chance of stealing food."
         << endl << endl;

    cout << "Do you want to try steal some food?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Enter your choice (1-2): ";
    choice = validInput(YES, NO);

    cout << endl;

    //Trying to steal food
    if (choice == YES)
    {
        //Used to determine if food is stolen
        int stealFood = rand() % 100 + 1;

        //Comparing stealChance to stealFood value to see if stole food
        if (stealFood <= stealChance)
        {
            cout << "You successfully stole some " << item << "!" << endl;
            cout << "If you eat it, you will feel more focused, " << endl
                 << "making it more difficult to be captured and" << endl
                 << "increasing the steps you can take by 5." << endl << endl;

                //Adding food to inventory
                user->addItem(item);
        }

        //Getting caught if steal chance not high enough
        else
        {
            int stepsLost = 5;

            cout << "A chef spotted you and alerted the guards!" << endl;

            //Decreasing steps
            user->decreaseSteps(stepsLost);
            cout << "The steps you can take before being caught "
                 << "is now " << user->getSteps() << "." << endl << endl;
        }
    }

    //Deciding not to steal
    else
    {
        cout << "You decide not to risk stealing right now." << endl;
        cout << "You should leave before someone sees you." << endl << endl;
    }
    
}


/***********************************************************************
** Description: Void member function eventAlreadyPlayed is used when
**              the event function has already played during the turn.
**              Tells the player that it is risky to stay in one place
**              for too long and they should try again later.
***********************************************************************/
void Kitchen::eventAlreadyPlayed()
{
    cout << "You have spent too much time here!" << endl;
    cout << "If you stay here much longer, you may get spotted." << endl;
    cout << "Try coming back later." << endl << endl;
}