/*****************************************************************************************
 ** Program Filename:  Creature.cpp
 ** Author:  Meredith Kiessling
 ** Date:  14.2.2016
 ** Description: Base Creature Class- abstract!
 ** Input:
 ** Output:
 *****************************************************************************************/

#include "Creature.hpp"
#include "Die.hpp"
#include<ctime>
#include<cstdlib>
#include<cmath>

/**************************************************************************************
 ** Function: BlueMen()
 ** Description: default constructor
 ** Parameters:
 ** Pre-Conditions: uninitialized member variables
 ** Post-Conditions: everything set to 0
 **************************************************************************************/
Creature::Creature() {
    // TODO Auto-generated constructor stub
    this->armor = 0;
    this->att = 0;
    this->def = 0;
    this->qAttDie = 0;
    this->sAttDie = 0;
    this->sDefDie = 0;
    this->qDefDie = 0;
    this->strength = 0;
    this->name = "";
    attDie = new Die(qAttDie, sAttDie);
    defDie = new Die(qDefDie, sDefDie);
}

Creature::~Creature() {
    delete attDie;
    delete defDie;
}

/*getter for strength*/
int Creature::getStrength() {
    return strength;
}

/*setter for strength*/
void Creature::setStrength(int s) {
    strength = s;
}

/*getter for Attack Dice*/
Die* Creature::getAttDie() {
    return attDie;
}

/*getter for Defense Dice*/
Die* Creature::getDefDie() {
    return defDie;
}

/*getter for Creature name*/
std::string Creature::getName() {
    return name;
}

