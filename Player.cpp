/***********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Implementation file for the Player class. Has functions
**               to get and increase/decrease step count, get and
**               increase steal chance, get vector containing player's 
**               items, get number of items in player's inventory, print
**               items, select an item, use an item, add and remove an
**               item, determine if player has book of spells, determine
**               if player has key ring, have player eat food, and have 
**               player use guard uniform.
***********************************************************************/

#include "Player.hpp"


/***********************************************************************
** Description: Default constructor for the Player class, which is used
**              to initialize the member variables.
***********************************************************************/
Player::Player()
{
    //Number of steps player starts with
    steps = 50;
    
    //Percent chance of stealing an item
    stealChance = 25;

    //Max number of items inventory can hold
    maxItems = 5;
}


/***********************************************************************
** Description: Member function getSteps returns the number of steps
**              the player currently has.
***********************************************************************/
int Player::getSteps()
{
    return steps;
}


/***********************************************************************
** Description: Void member function decreaseSteps takes in an integer
**              as a parameter representing how many steps should be
**              subtracted from the total number of steps. Subtracts
**              amount from the current steps value. If new steps amount
**              is less than 0, sets steps to 0.
***********************************************************************/
void Player::decreaseSteps(int decreaseAmount)
{
    steps -= decreaseAmount;

    //Cannot have negative number of steps
    if (steps < 0)
    {
        steps = 0;
    }
}


/***********************************************************************
** Description: Void member function increaseSteps takes in an integer
**              as a parameter representing how many steps should be
**              added to the total number of steps. Adds amount to the
**              current steps value. If new steps amount is greater than
**              999, sets steps to 999.
***********************************************************************/
void Player::increaseSteps(int increaseAmount)
{
    steps += increaseAmount;

    //Max number of steps is 999
    if (steps > 999)
    {
        steps = 999;
    }
}


/***********************************************************************
** Description: Member function getStealChance returns the percent 
**              chance the player has to steal an item.
***********************************************************************/
int Player::getStealChance()
{
    return stealChance;
}


/***********************************************************************
** Description: Void member function increaseStealChance takes in an
**              integer as a parameter for how much the chance of
**              stealing an item should increase by. Adds this to
**              stealChance.
***********************************************************************/
void Player::increaseStealChance(int amount)
{
    stealChance += amount;

    //Cannot have steal chance higher than 100
    if (stealChance > 100)
    {
        stealChance = 100;
    }
}


/***********************************************************************
** Description: Member function getNumItems returns the number of items
**              the player currently has.
***********************************************************************/
int Player::getNumItems()
{
    return items.size();
}


/***********************************************************************
** Description: Member function getItems returns the vector holding the
**              player's items.
***********************************************************************/
vector<string> Player::getItems()
{
    return items;
}


/***********************************************************************
** Description: Void member function printItems prints the items in the
**              player's inventory. If the player has no items, prints
**              that they do not have anything in their inventory.
***********************************************************************/
void Player::printItems()
{
    //If player has no items in inventory
    if (items.size() == 0)
    {
        cout << "You do not have any items in your inventory." << endl << endl;
    }

    //Printing items in inventory
    else
    {
        int itemNum;

        cout << "Here are the items in your inventory: " << endl;

        //Printing list of items
        for (int i = 0; i < items.size(); i++)
        {
            itemNum = i + 1;
            cout << itemNum << ": " << items[i] << endl;
        }

        cout << endl;
    }
    
}


/***********************************************************************
** Description: Member function selectItem asks the player which item 
**              they want to use. Returns the selected item's index
**              number.
***********************************************************************/
int Player::selectItem()
{
    int choice,
        indexNum;
    int FIRST_ITEM = 1,
        LAST_ITEM = items.size();

    string chosenItem;

    //Printing items for player to select
    printItems();

    cout << "Which item do you want to use? " << endl;
    cout << "Enter the item's number: ";
    choice = validInput(FIRST_ITEM, LAST_ITEM);

    cout << endl;

    //Getting the index number of the selected item
    indexNum = choice - 1;

    return indexNum;
}


/***********************************************************************
** Description: Member function useItem calls selectItem to select what
**              item the user wants to use. Calls eatFood if user chose
**              food to eat or useUniform if chose to put on the guard
**              uniform. Returns the name of the item as a string.
***********************************************************************/
string Player::useItem()
{
    int chosenItem;

    string itemName;

    //Selecting an item from inventory to use
    chosenItem = selectItem();

    itemName = items[chosenItem];

    //Eats food to increase steps
    if (itemName == "food")
    {
        eatFood(chosenItem);
        cout << endl << endl;
    }

    //Uses uniform to increase steal chance
    else if(itemName == "guard uniform")
    {
        useUniform(chosenItem);
    }
    
    return itemName;
}


/***********************************************************************
** Description: Void member function addItem takes in a string as a 
**              parameter representing the item that will be added to
**              the player's inventory. Has player remove an item if
**              they are holding too many. Adds new item to inventory.
***********************************************************************/
void Player::addItem(string newItem)
{
    //Remove an item if adding item will make inventory go over its limit
    if (items.size() == maxItems)
    {
        removeItem();
    }

    //Adding new item to inventory
    items.push_back(newItem);

    cout << "Added " << newItem << " to your inventory." << endl << endl;
}


/***********************************************************************
** Description: Void member function removeItem has player remove or use
**              one item from their inventory if they are carrying too
**              many. Deletes the used/removed item.
**              Source: http://www.cplusplus.com/reference/vector/
**                      vector/erase/
***********************************************************************/
void Player::removeItem()
{
    int choice,
        indexNum; 
    const int MIN_CHOICE = 1,
              MAX_CHOICE = items.size();

    cout << "You have reach the maximum amount of items." << endl;
    cout << "Choose an item to remove or use in your inventory:" << endl;

    //Listing items in inventory
    printItems();

    cout << "Enter the nunber of the item you want to remove or use: ";
    choice = validInput(MIN_CHOICE, MAX_CHOICE);

    cout << endl;

    //Finding index number of item selected
    indexNum = choice - 1;

    //Cannot get rid of important items
    while (items[indexNum] == "key ring" ||
           items[indexNum] == "book of spells" ||
           items[indexNum] == "library map")
    {
        cout << "This is an important item! You cannot remove it." 
             << endl << endl;
        cout << "Enter another choice: ";
        choice = validInput(MIN_CHOICE, MAX_CHOICE);

        //Finding index number of new item selected
        indexNum = choice - 1;
    }

    //Eating food if chosen to remove
    if (items[indexNum] == "food")
    {
        eatFood(indexNum);
    }

    //Using Uniform if chosen to remove
    else if (items[indexNum] == "guard uniform")
    {
        useUniform(indexNum);
    }

    //Removing item
    else
    {
        cout << "You removed the " << items[indexNum]
             << " from your inventory." << endl
             << endl;
        items.erase(items.begin() + (indexNum));
    }
}


/***********************************************************************
** Description: Member function haveBook returns true if the book of 
**              spells is in the player's inventory or false if they
**              do not have the book.
***********************************************************************/
bool Player::haveBook()
{
    bool bookInInventory = false;

    //Checking to see if book of spells is in inventory
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i] == "book of spells")
        {
            bookInInventory = true;
        }
    }

    return bookInInventory;
}


/***********************************************************************
** Description: Member function haveKey returns true if the key ring is
**              in the player's inventory or false if they do not have
**              the key ring.
***********************************************************************/
bool Player::haveKey()
{
    bool keyInInventory = false;

    //Checking to see if key ring is in inventory
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i] == "key ring")
        {
            keyInInventory = true;
        }
    }

    return keyInInventory;
}


/***********************************************************************
** Description: Void member function eatFood has the player eat food
**              to increase the number of steps they can take.
***********************************************************************/
void Player::eatFood(int indexNum)
{
    int stepsGained = 5;

    //Step amount increases after eating
    increaseSteps(stepsGained);

    cout << "You ate some food and feel more alert!" << endl;
    cout << "The steps you can take before being caught increased to "
         << steps << "." << endl;

    //Removing food from inventory
    items.erase(items.begin() + indexNum);
}


/***********************************************************************
** Description: Void member function useUniform uses the guard uniform, 
**              which increases the player's chance to steal an item. 
**              Removes guard uniform from inventory.
***********************************************************************/
void Player::useUniform(int indexNum)
{
    stealChance += 50;

    cout << "You put on the guard uniform." << endl;
    cout << "Your steal chance is now " << stealChance << "%." << endl << endl;

    //Removing guard uniform from inventory
    items.erase(items.begin() + indexNum);
}