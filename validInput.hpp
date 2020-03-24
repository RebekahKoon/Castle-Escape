/*********************************************************************
** Program name: finalProject
** Author:       Rebekah Koon
** Date:         8/7/19
** Description:  Header file for validInput function that determines
**               if a user entered a number within the correct range.
**               If not within range, asks user to reenter their input
**               until a valid answer is selected.
*********************************************************************/

#ifndef VALID_INPUT_HPP
#define VALID_INPUT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>

using std::atoi;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::istringstream;
using std::noskipws;
using std::fixed;
using std::showpoint;
using std::setprecision;

int validInput(int, int);

#endif