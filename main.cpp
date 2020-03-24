/**********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  This program plays a game in which the player is a
**               thief who has broken into a castle to steal treasure.
**               After the player decides if they want to play, they
**               can decide to either perform an event within the space
**               they occupy, print the items currently in their
**               inventory, select an item to use, print a map of the
**               castle, move to a new space, or quit the game. If they
**               decide to move to a new space, the player enters what
**               direction they want to move in and, if there is a room
**               in that direction, they move to that space, where they
**               get a list of actions they can perform for that space.
**               The player collects items along the way that will help
**               them finish the game. The player wins by opening the
**               treasure chest in the tower. The player can choose to
**               play again or quit.
**********************************************************************/

#include "Menu.hpp"
#include "Game.hpp"

#include <cstdlib>
#include <ctime>

//Used to determine whether the game will be played
enum UserChoice {PLAY = 1, DONT_PLAY};

int main()
{
    int chooseToPlay;

    //Used for generating random integers
    unsigned seed;
    seed = time(0);
    srand(seed);
    
    Menu gameMenu;
    Game *invadeCastle;

    //Determining if user wants to play
    chooseToPlay = gameMenu.chooseToPlay();

    //If user wants to play
    while (chooseToPlay == PLAY)
    {
        invadeCastle = new Game;

        //Playing game
        invadeCastle->playGame();

        //After game is finished
        delete invadeCastle;

        //Determining if user wants to play again
        chooseToPlay = gameMenu.playAgain();
    }

    cout << "Goodbye!" << endl;

    return 0;
}