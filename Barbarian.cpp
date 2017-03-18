/*****************************************************************************************
 ** Program Filename:  Barbarian.cpp
 ** Author:  Meredith Kiessling
 ** Date:  14.2.2016
 ** Description: Derived from Creature Class- Barbarian BEAST!
 ** Input:
 ** Output:
 *****************************************************************************************/

#include "Barbarian.hpp"
#include<iostream>
using namespace std;

/**************************************************************************************
 ** Function: Barbarian() : Creature()
 ** Description: default constructor
 ** Parameters:
 ** Pre-Conditions: uninitialized member variables
 ** Post-Conditions: initializes member variables
 **************************************************************************************/
Barbarian::Barbarian() : Creature() {
    this->armor = 0;
    this->att = 0;
    this->def = 0;
    this->qAttDie = 2;
    this->sAttDie = 6;
    this->sDefDie = 6;
    this->qDefDie = 2;
    this->strength = 12;
    this->name = "Barbarian";
    attDie = new Die(qAttDie, sAttDie);
    defDie = new Die(qDefDie, sDefDie);

}

Barbarian::~Barbarian() {

}

/**************************************************************************************
 ** Function: attack()
 ** Description: attack function - basic
 ** Parameters:  Creature Pointer (Opponent 2)
 ** Pre-Conditions:
 ** Post-Conditions: Barbarian attacks Opponent 2 with its attack dice. Returns
 ** 				 total damage inflicted
 **************************************************************************************/
int Barbarian::attack(Creature *beast) {
    if (strength > 0) {
        int damage;
        damage = attDie->roll();
        cout << "attack: " << damage << "   ";
        return damage;
    } else {
        cout << "This Barbarian's strength is 0 and has been removed from combat."
                << endl;
        return 0;
    }
}

/**************************************************************************************
 ** Function: defense()
 ** Description: defense function - basic. Barbarian rolls its defense die to counter
 ** 			the damage points inflicted by the other Opponents attack
 ** Parameters:  int damage (returned from Opponent 1's attack function)
 ** Pre-Conditions: total damage points from other Opponent; strength unmodified
 ** Post-Conditions: Barbarian strength reduced (attack - (defense + armor))
 **************************************************************************************/
void Barbarian::defense(int damage) {
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

        /*if temp strength is negative, assign strength = 0 */
        if (temp < 0) {
            strength = 0;
            cout << getName() << "strength now =" << strength << endl;
            cout << "This Barbarian has been removed from combat." << endl;
        } else {
            strength = temp;
            cout << getName() << " strength now =" << strength << endl;
        }
    } else {
        cout << "Barbarian is out of combat." << endl;
    }
}
