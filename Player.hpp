/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Header file for the Player class. Has functions to get
**               and increase/decrease step count, get and increase
**               steal chance, get vector containing player's items, get
**               number of items in player's inventory, print items,
**               select an item, use an item, add or remove and item,
**               determine if player has the book of spells, determine 
**               if player has key ring, have player eat food, and have 
**               player use guard uniform.
***********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "validInput.hpp"

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Player
{
    private:
        int steps;
        int stealChance;

        vector<string> items;
        int maxItems;

    public:
        Player();

        int getSteps();
        void decreaseSteps(int);
        void increaseSteps(int);

        int getStealChance();
        void increaseStealChance(int);
        
        int getNumItems();
        vector<string> getItems();
        void printItems();
        int selectItem();
        string useItem();
        void addItem(string);
        void removeItem();

        bool haveBook();
        bool haveKey();

        void eatFood(int);
        void useUniform(int);
};

#endif