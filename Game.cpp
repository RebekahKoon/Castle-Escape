/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Implementation file for the Game class. Contains 
**               functions that play the game by determining if the user
**               has run out of steps or already met the objective, 
**               perform an action in a space, move the player to a new 
**               space, and print the map with the player's location.
***********************************************************************/

#include "Game.hpp"


/*********************************************************************
** Description: Default constructor for the Game class, which sets up
**              the linked list of spaces for the user to move to
**              when playing the game. Also dynamically allocates 
**              memory for a Player object for user information and 
**              sets the quit and performedEvent variables.
*********************************************************************/
Game::Game()
{
    //Creating all of the spaces in the game.
    mainHall = new MainHall;
    library = new Library;
    diningRoom = new DiningRoom;
    kitchen = new Kitchen;
    courtyard = new Courtyard;
    trainingArea = new TrainingArea;
    tower = new Tower;
    
    //Setting adjacent spaces for main hall
    mainHall->setLeft(library);
    mainHall->setRight(diningRoom);
    mainHall->setTop(courtyard);
 
    //Setting adjacent space for library
    library->setRight(mainHall);
    
    //Setting adjacent spaces for dining room
    diningRoom->setLeft(mainHall);
    diningRoom->setTop(kitchen);

    //Setting adjacent space for kitchen
    kitchen->setBottom(diningRoom);
    
    //Setting adjacent spaces for courtyard
    courtyard->setLeft(trainingArea);
    courtyard->setTop(tower);
    courtyard->setBottom(mainHall);

    //Setting adjacent space for guard room
    trainingArea->setRight(courtyard);

    //Setting adjacent space for tower
    tower->setBottom(courtyard);

    //Current position of the player
    currentPosition = mainHall;

    //Used to keep track of player's game information
    user = new Player;

    //Determines if user quits the game early
    quit = false;

    //Determines if special event has already been played
    performedEvent = false;
}


/*********************************************************************
** Description: Void member function playGame is used for running the
**              game. While the user has not yet run out of steps and
**              the user has not already won or quit the game, prints
**              the map, prints the room description, and uses the
**              performAction function to have user pick their next 
**              action to perform. If the user runs out of steps, 
**              quits the game, or wins, the game ends.
*********************************************************************/
void Game::playGame()
{
    //Finding how many steps user starts with
    int stepAmount = user->getSteps();

    cout << "You have snuck into the greedy king's castle!" << endl;
    cout << "You have heard rumors of a grand treasure hidden "
         << "within the castle's tower." << endl;
    cout << "Your mission is to find and steal the treasure." << endl;
    cout << "The people in your village will benefit greatly "
         << "from the fortune it will bring." << endl;
    cout << "You have 50 steps before you are discovered." << endl;
    cout << "Your chance of stealing an item starts at 25%." << endl;
    cout << "You sneak in through a window to begin your heist." 
         << endl << endl;

    //Game ends if run out of steps, win the game, or quit the game
    while(stepAmount != 0 && !(currentPosition->gameWon()) && !quit)
    {
        //Can perform special event in new location
        performedEvent = false;

        //Printing map of castle
        printMap();
        cout << "You have " << stepAmount << " steps left." << endl << endl;

        //Printing current room's description
        currentPosition->roomDescription();

        //Selecting action to do in the space
        performAction();

        //Determining step amount
        stepAmount = user->getSteps();

        //Game is over if run out of steps
        if (stepAmount == 0)
        {
            cout << "You hear the sound of an army of footsteps." << endl;
            cout << "You took too long finding the treasure." << endl;
            cout << "The guards surround you and throw you in the dungeon."
                 << endl;
            cout << "You have failed your mission." << endl << endl;
        }

        //Exits game if quit
        else if (quit == true)
        {
            cout << "Thanks for playing!" << endl << endl;
        }

        else if (currentPosition->gameWon())
        {
            cout << "Congratulations! You won!" << endl << endl;
        }
    }
}


/*********************************************************************
** Description: Void member function performAction asks user to type
**              the number of the action they want to perform. Calls
**              the function associated with the action they want to
**              perform.
*********************************************************************/
void Game::performAction()
{
    int choice;

    //Used to get menu option for the current space's special event
    string specialEventOption = currentPosition->getMenuOption();

    //Cannot continue if out of steps
    if (user->getSteps() == 0)
    {
        choice = QUIT;
    }

    //Printing menu of options player can choose to do within the space
    else
    {
        choice = gameMenu.chooseAction(specialEventOption);
    }

    //Picking action to perform based on choice
    switch (choice)
    {
    case PLAY_EVENT:
        //If special event hasn't been performed during this step
        if (!performedEvent)
        {
            currentPosition->event(user);
            performedEvent = true;
        }

        //If event already performed during this step
        else
        {
            currentPosition->eventAlreadyPlayed();
        }
        
        break;

    case PRINT_ITEMS:
        user->printItems();
        break;

    case USE_ITEM:
        currentPosition->chooseItem(user);
        break;

    case VIEW_MAP:
        printMap();
        break;

    case MOVE:
        movePlayer();
        break;

    case QUIT:
        quit = true;
    }

    //Picking another action if didn't select move, quit, or have won
    if (choice != MOVE && choice != QUIT && !(currentPosition->gameWon()))
    {
        performAction();
    }
}


/***********************************************************************
** Description: Void member function movePlayer uses the Menu class to 
**              ask the user to type in the number of the direction they
**              to move in. If there is nothing that way, calls 
**              performAction to perform another action. If they can 
**              move in that direction, moves the player to the space
**              in that direction adjacent to their current space.
***********************************************************************/
void Game::movePlayer()
{
    int choice;
    Space *newLocation;

    //Finding the direction user wants to move in
    choice = gameMenu.chooseNewSpace();

    //Determining what direction the user will move in
    switch (choice)
    {
    case TOP:
        newLocation = currentPosition->getTop();
        break;

    case RIGHT:
        newLocation = currentPosition->getRight();
        break;
    
    case LEFT:
        newLocation = currentPosition->getLeft();
        break;

    case BOTTOM:
        newLocation = currentPosition->getBottom();
        break;
    }

    //newLocation returning null means there is not a space in that direction
    if (newLocation == NULL)
    {
        //Player picks new action
        performAction();
    }

    //Moving to a new space if there is a space in the selected direction
    else
    {
        int stepsToLocation = 1;

        //Moving player to new location
        currentPosition = newLocation;

        //Decreasing step count to move to next space
        user->decreaseSteps(stepsToLocation);

        performedEvent = false;
    }
}


/*********************************************************************
** Description: Void member function printMap prints the user's map
**              and a message saying where the user is currently at.
*********************************************************************/
void Game::printMap()
{
    cout << "                   ---------------"                    << endl
         << "                   |    Tower    |"                    << endl
         << "                   ---------------"                    << endl
         << "                          ||"                          << endl
         << "---------------    ---------------    ---------------" << endl
         << "|Training Area|====|  Courtyard  |    |   Kitchen   |" << endl
         << "---------------    ---------------    ---------------" << endl
         << "                          ||                 ||"       << endl
         << "---------------    ---------------    ---------------" << endl
         << "|   Library   |====|  Main Hall  |====| Dining Room |" << endl
         << "---------------    ---------------    ---------------" << endl;

    cout << "You are currently in the " << currentPosition->getName() << "."
         << endl << endl;
}


/*********************************************************************
** Description: Deconstructor that deallocates the dynamically 
**              allocated memory in the Game class.
*********************************************************************/
Game::~Game()
{
    delete mainHall;
    delete library;
    delete diningRoom;
    delete kitchen;
    delete courtyard;
    delete trainingArea;
    delete tower;

    delete user;
}