/*****************************************************************************************
 ** Program Filename:  Die.cpp
 ** Author:  Meredith Kiessling
 ** Date:  14.2.2016
 ** Description: Die Class- creates q, dice of n sides and then sums their rolls together
 ** Input: int quantity, int sides
 ** Output: total roll value for q dice with s sides
 *****************************************************************************************/

#include "Die.hpp"
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

/**************************************************************************************
 ** Function: Die()
 ** Description: initializes die to 0 sides
 ** Parameters:
 ** Pre-Conditions: 0 die with 0 sides
 ** Post-Conditions: 0 dice with 0 sides
 **************************************************************************************/
Die::Die() {
    quantity = 0;
    sides = 0;
    seed = 0;
    seed = time(0);
    srand(seed);
}
/**************************************************************************************
 ** Function: Die(quantity, sides)
 ** Description: initializes quantity, q dice of sides, s
 ** Parameters: int quantity, int sides
 ** Pre-Conditions: 0 die with 0 sides
 ** Post-Conditions: q dice with s sides
 **************************************************************************************/
Die::Die(int q, int s) {
    quantity = q;
    sides = s;
    seed = 0;
    seed = time(0);
    srand(seed);
}

Die::~Die() {
    // TODO Auto-generated destructor stub
}

/**************************************************************************************
 ** Function: roll()
 ** Description: rolls n, quantity of die and sums them together and returns that sum
 ** Parameters:
 ** Pre-Conditions: roll = 0
 ** Post-Conditions: roll > 0
 **************************************************************************************/
int Die::roll() {
    int d1 = 0;

    for (int i = 0; i < quantity; i++) {
        int dtemp = rand() % sides + 1;
        d1 += dtemp;
    }

    return d1; /*returns largest value from the quantity of dice rolled*/
}
