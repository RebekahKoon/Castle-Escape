/**********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Implementation file for the Menu class. Contains 
**               functions that give user the option to play the game,
**               choose an action to perform in the game, move to a new
**               space, and play the game again.
**********************************************************************/

#include "Menu.hpp"


/*********************************************************************
** Description: Member function chooseToPlay asks the user if they 
**              want to play the game. Returns the user's choice.
*********************************************************************/
int Menu::chooseToPlay()
{
    int choice;

    //Game description
    cout << "In this game, you play as a thief who" 
         << " breaks into a castle to steal treasure." << endl;
    cout << "You can take 50 steps before a guard finds you." << endl;
    cout << "If you run out of steps, you are caught and lose." << endl;
    cout << "At some points in the game, you can try to steal items." << endl;
    cout << "Your chance of stealing an item starts at 25%." << endl;
    cout << "However, there are ways to increase your steal chance." << endl;
    cout << "Find and collect items along the way that will help you." << endl;
    cout << "Steal the treasure to win the game!" << endl << endl;

    cout << "Would you like to play the game?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl << endl;

    cout << "Enter your choice (1-2): ";
    choice = validInput(YES, NO);

    return choice;
}


/***********************************************************************
** Description: Member function chooseAction takes a string as a 
**              parameter for the menu option of the special event
**              that can be performed in the current space. User chooses
**              what action will be performed. Returns user's choice.
***********************************************************************/
int Menu::chooseAction(string menuOption)
{
    int choice;
    const int CHOICE_MIN = 1,
              CHOICE_MAX = 6;

    cout << "What would you like to do?" << endl;
    cout << "1. " << menuOption << endl;
    cout << "2. View your item inventory" << endl;
    cout << "3. Use an item" << endl;
    cout << "4. View castle map" << endl;
    cout << "5. Move to another room" << endl;
    cout << "6. End your heist" << endl << endl;
    cout << "Select your choice (1-6): ";
    choice = validInput(CHOICE_MIN, CHOICE_MAX);

    cout << endl;

    return choice;
}


/***********************************************************************
** Description: Member function chooseNewSpace gives the user a list of
**              directions they can move in. User selects in what 
**              direction they want to move. Returns the user's choice.
***********************************************************************/
int Menu::chooseNewSpace()
{
    int choice;
    const int CHOICE_MIN = 1,
              CHOICE_MAX = 4;

    cout << "In what direction would you like to move?" << endl;
    cout << "1. Forward" << endl;
    cout << "2. Right" << endl;
    cout << "3. Left" << endl;
    cout << "4. Down" << endl << endl;
    cout << "Enter your choice (1-4): ";
    choice = validInput(CHOICE_MIN, CHOICE_MAX);

    cout << endl;

    return choice;
}


/*********************************************************************
** Description: Member function playAgain asks the user if they want
**              to play the game again. Returns the user's choice.
*********************************************************************/
int Menu::playAgain()
{
    int choice;

    cout << "Do you want to play again?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl << endl;
    cout << "Enter your choice (1-2): ";
    choice = validInput(YES, NO);

    return choice;
}