/*****************************************************************************************
 ** Program Filename:  Medusa.cpp
 ** Author:  Meredith Kiessling
 ** Date:  14.2.2016
 ** Description: Derived from Creature Class- Medusa!
 ** Input:
 ** Output:
 *****************************************************************************************/

#include "Medusa.hpp"
#include<iostream>
using namespace std;

/**************************************************************************************
 ** Function: Medusa() : Creature()
 ** Description: default constructor
 ** Parameters:
 ** Pre-Conditions: uninitialized member variables
 ** Post-Conditions: initializes member variables
 **************************************************************************************/
Medusa::Medusa() : Creature() {

    this->armor = 3;
    this->att = 0;
    this->def = 0;
    this->qAttDie = 2;
    this->sAttDie = 6;
    this->sDefDie = 6;
    this->qDefDie = 1;
    this->strength = 8;
    this->name = "Medusa";
    attDie = new Die(qAttDie, sAttDie);
    defDie = new Die(qDefDie, sDefDie);
}

Medusa::~Medusa() {

}

/**************************************************************************************
 ** Function: attack(Creature *beast)
 ** Description: attack function - MODIFIED. If Medusa rolls a 12, Medusa Glare Attack
 ** 			initiated. Medusa automatically wins, and the opponent's strength is
 ** 			set to 0.
 ** Parameters:  Creature Pointer (Opponent 2)
 ** Pre-Conditions:
 ** Post-Conditions: Medusa attacks Opponent with its attack dice. Returns
 ** 				 total damage inflicted or sets Opponent's strength to 0
 **************************************************************************************/
int Medusa::attack(Creature *beast) {
    if (strength > 0) {
        int damage;
        damage = attDie->roll();

        /*initiate Medusa Glare Attack if 12 is rolled*/
        if (damage == 12) {
            cout << "Attack! Medusa Glare! Medusa wins!";
            beast->setStrength(0); /* Opponent Strength set to 0*/
            return 0;
        }

        cout << "Medusa attack: " << damage << "    ";

        return damage;
    } else {
        cout << "This Medusa's strength is 0 and has been removed from combat" << endl;
        return 0;
    }
}

/**************************************************************************************
 ** Function: defense()
 ** Description: defense function - basic. Medusa rolls its defense die to counter
 ** 			the damage points inflicted by the other Opponents attack
 ** Parameters:  int damage (returned from Opponent 1's attack function)
 ** Pre-Conditions: total damage points from other Opponent; strength unmodified
 ** Post-Conditions: Barbarian strength reduced (attack - (defense + armor))
 **************************************************************************************/
void Medusa::defense(int damage) {
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
            cout << getName() << " strength now =" << strength << endl;
            cout << "This Medusa has been removed from combat." << endl;
        } else {
            strength = temp;
            cout << getName() << " strength now = " << strength << endl;
        }
    } else {
        cout << "This Medusa is out of combat." << endl;
    }
}
