/*********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Source file for validInput function that determines
**               if a user entered a number within the correct range.
**               If not within range, asks user to reenter their input
**               until a valid answer is selected.
*********************************************************************/

#include "validInput.hpp"

/***********************************************************************
** Description: Function isValid takes two integers representing the
**              minimum and maximum range for an integer as parameters.
**              Takes user input and, if not a valid integer, asks user
**              to reenter their input. If valid, returns the integer
**              inputted by the user.
**              Source: Adapted from my lab 1 assignment.
***********************************************************************/
int validInput(int minNumber, int maxNumber)
{
    bool valid;
    int numberInt;
    string answer;

    do
    {
        getline(cin, answer);
        valid = true;

        //If string is empty
        if (answer.empty())
        {
            valid = false;
        }

        //If answer is single character, must be a digit
        else if ((answer.length() == 1) && (!isdigit(answer[0])))
        {
            valid = false;
        }

        else
        {
            //Checking to see if the input is a negative integer
            if ((!isdigit(answer[0])) && (answer[0] != '-'))
            {
            valid = false;
            }

            //Making sure other characters in the string are digits
            for (int i = 1; i < answer.length(); i++)
            {
                if (!isdigit(answer[i]))
                {
                    valid = false;
                }
            }
        }

        if (valid)
        {
            //Converting to an integer to check if it is within the min/max range
            numberInt = atoi(answer.c_str());

            //Checking to see if the integer is between the min/max range
            if (numberInt < minNumber || numberInt > maxNumber)
            {
                valid = false;
            }
        }

        //Reenter input if not a valid response
        if (!valid)
        {
            cout << "Please only type integers from "
                 << minNumber << " to " << maxNumber << ": ";
        }
    } while (valid == false);

    return numberInt;
}