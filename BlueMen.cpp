/*****************************************************************************************
 ** Program Filename:  BlueMen.cpp
 ** Author:  Meredith Kiessling
 ** Date:  14.2.2016
 ** Description: Derived from Creature Class- Blue Men!
 ** Input:
 ** Output:
 *****************************************************************************************/

#include "BlueMen.hpp"
#include<iostream>

/**************************************************************************************
 ** Function: BlueMen()
 ** Description: default constructor
 ** Parameters:
 ** Pre-Conditions: uninitialized member variables
 ** Post-Conditions: initializes member variables
 **************************************************************************************/
BlueMen::BlueMen() : Creature() {
    this->armor = 3;
    this->att = 0;
    this->def = 0;
    this->qAttDie = 2;
    this->sAttDie = 10;
    this->sDefDie = 6;
    this->qDefDie = 3;
    this->strength = 12;
    this->name = "Blue Men";
    attDie = new Die(qAttDie, sAttDie);
    defDie = new Die(qDefDie, sDefDie);
}

BlueMen::~BlueMen() {

}

/**************************************************************************************
 ** Function: attack()
 ** Description: attack function - basic
 ** Parameters:  Creature Pointer (Opponent 2)
 ** Pre-Conditions:
 ** Post-Conditions: Blue Men attacks Opponent 2 with its attack dice. Returns
 ** 				 total damage inflicted
 **************************************************************************************/
int BlueMen::attack(Creature *beast) {
    if (strength > 0) {
        int damage;
        damage = attDie->roll();
        cout << "Blue Men attack: " << damage << "   ";
        return damage;
    } else {
        cout << "This Blue Men's strength is 0 and has been removed from combat." << endl;
        return 0;
    }
}

/**************************************************************************************
 ** Function: defense()
 ** Description: defense function - MODIFIED. Blue Men rolls its defense dice to counter
 ** 			the damage points inflicted by the other Opponents attack. The number of
 ** 			defense dice used decreases with the loss of strength points.
 ** Parameters:  int damage (returned from Opponent 1's attack function)
 ** Pre-Conditions: total damage points from other Opponent; strength unmodified
 ** Post-Conditions: BlueMen strength reduced (attack - (defense + armor))
 **************************************************************************************/
void BlueMen::defense(int damage) {
    if (strength > 0) {
        /*temp holds temporary strength points pending logic approval*/
        int temp;
        int defense;

        /*use three defense dice, if strength > 8*/
        if (8 < strength && strength < 13) {
            defense = defDie->roll();
        }

        /*use two defense dice, if strength > 4*/
        if (4 < strength && strength < 9) {
            cout << "Mob Strength Down! Rolling 2 dice" << endl;
            Die* altDefDie = new Die((qDefDie - 1), sDefDie);
            defense = altDefDie->roll();
            delete altDefDie;
        }

        /*use one defense die, if strength > 0*/
        if (0 < strength && strength < 5) {
            cout << "Mob Strength Down! Rolling 1 die!" << endl;
            Die* altDefDie = new Die((qDefDie - 2), sDefDie);
            defense = altDefDie->roll();
            delete altDefDie;
        }

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
            cout << getName() << "strength now = " << strength << endl;
            cout << "This Blue Men has been removed from combat." << endl;
        } else {
            strength = temp;
            cout << getName() << " strength now = " << strength << endl;
        }
    } else {
        cout << "This Blue Men is out of combat" << endl;
    }
}
