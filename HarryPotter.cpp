/*****************************************************************************************
 ** Program Filename:  HarryPotter.cpp
 ** Author:  Meredith Kiessling
 ** Date:  14.2.2016
 ** Description: Derived from Creature Class- Harry Potter!
 ** Input:
 ** Output:
 *****************************************************************************************/

#include "HarryPotter.hpp"
#include<iostream>

/**************************************************************************************
 ** Function: Harry Potter() : Creature()
 ** Description: default constructor
 ** Parameters:
 ** Pre-Conditions: uninitialized member variables
 ** Post-Conditions: initializes member variables
 **************************************************************************************/
HarryPotter::HarryPotter() : Creature() {
    this->armor = 0;
    this->att = 0;
    this->def = 0;
    this->qAttDie = 2;
    this->sAttDie = 6;
    this->sDefDie = 6;
    this->qDefDie = 2;
    this->strength = 10;
    this->name = "Harry Potter";
    attDie = new Die(qAttDie, sAttDie);
    defDie = new Die(qDefDie, sDefDie);
    this->isFirstLife = true;

}

HarryPotter::~HarryPotter() {

}

/**************************************************************************************
 ** Function: attack()
 ** Description: attack function - basic
 ** Parameters:  Creature Pointer (opponent 2)
 ** Pre-Conditions:
 ** Post-Conditions: Harry Potter attacks Opponent 2 with its attack dice. Returns
 ** 				 total damage inflicted
 **************************************************************************************/
int HarryPotter::attack(Creature *beast) {
    if (strength > 0) {
        int damage;
        damage = attDie->roll();
        cout << "Potter attack: " << damage << "   ";
        return damage;
    } else {
        cout << "Harry Potter's strength is 0 and has been removed from combat." << endl;
        return 0;
    }
}

/**************************************************************************************
 ** Function: defense()
 ** Description: defense function - MODIFIED. Potter rolls its defense die to counter
 ** 			the damage points inflicted by the other Opponents attack. The first
 ** 			time Harry Potter's strength reaches 0, he is automatically
 ** 			regenerated with a strength of 20. This only happens once.
 ** Parameters:  int damage (returned from Opponent 1's attack function)
 ** Pre-Conditions: total damage points from other Opponent; strength unmodified
 ** Post-Conditions: Harry Potter strength reduced (attack - (defense + armor))
 **************************************************************************************/
void HarryPotter::defense(int damage) {
    if (strength > 0) {
        /*temp holds temporary strength points pending logic approval*/
        int temp;
        int defense = defDie->roll();

        cout << "defense roll: " << defense << endl;

        int netDefense = defense + armor;

        int netDamage = damage - netDefense;

        if (netDamage < 0) {
            netDamage = 0;
        }

        cout << "net damage is: " << netDamage << endl;

        temp = strength - netDamage;

        /*if temp = 0, temp < 0 AND this is Harry's first life - REGENERATE*/
        if ((temp < 0 || temp == 0) && isFirstLife) {
            strength = 20;
            cout << "Sectumsempra! Harry Potter has been healed, and then some!" << endl;
            cout << getName() << "strength now = " << strength << endl;
            isFirstLife = false;
            return;
        }
        /*if temp = 0 and this is not Harry's first life, set strength = 0*/
        if (temp < 0 && !isFirstLife) {
            strength = 0;
            cout << getName() << " strength now = " << strength << endl;
            cout << "Harry Potter has been removed from combat." << endl;
        } else {
            strength = temp;
            cout << getName() << " strength now = " << strength << endl;
        }
    } else {
        cout << "Harry Potter is out of combat." << endl;
    }
}
