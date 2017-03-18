/*****************************************************************************************
 ** Program Filename:  Vampire.cpp
 ** Author:  Meredith Kiessling
 ** Date:  14.2.2016
 ** Description: Derived from Creature Class- Vampire! Vampire has a special defense
 **		The Vampire can glare his opponents into not attacking. NOTE TO TA: it is
 ** 		assumed that the 'attack' happens, but the vampire chooses whether or not
 ** 		to apply damage points pending if Glare Defense is initialized.
 ** Input:
 ** Output:
 *****************************************************************************************/

#include "Vampire.hpp"
#include<cstdlib>
#include<ctime>
#include<iostream>

/**************************************************************************************
 ** Function: Vampire() : Creature()
 ** Description: default constructor
 ** Parameters:
 ** Pre-Conditions: uninitialized member variables
 ** Post-Conditions: initializes member variables
 **************************************************************************************/
Vampire::Vampire() : Creature() {
    this->armor = 1;
    this->att = 0;
    this->def = 0;
    this->qAttDie = 1;
    this->sAttDie = 12;
    this->sDefDie = 6;
    this->qDefDie = 1;
    this->strength = 18;
    this->name = "Vampire";
    attDie = new Die(qAttDie, sAttDie);
    defDie = new Die(qDefDie, sDefDie);
    this->seed = 0; /*seed & srand() used to randomly use Vampire Glare Defense!*/
    seed = time(0);
    srand(seed);
}

Vampire::~Vampire() {

}

/**************************************************************************************
 ** Function: attack()
 ** Description: attack function - basic
 ** Parameters:  Creature Pointer (Opponent 2)
 ** Pre-Conditions:
 ** Post-Conditions: Vampire attacks Opponent 2 with its attack dice. Returns
 ** 				 total damage inflicted
 **************************************************************************************/
int Vampire::attack(Creature *beast) {
    if (strength > 0) {
        int damage;
        damage = attDie->roll();
        cout << "Vampire attack: " << damage << "   ";
        return damage;
    } else {
        cout << "This Vampire's strength is 0 and has been removed from combat" << endl;
        return 0;
    }
}

/**************************************************************************************
 ** Function: defense()
 ** Description: defense function - MODIFIED. Vampire has a special Charm Defense.
 ** 			If the Charm defense is used (50/50 probability), it does not allow the
 ** 			Opponent to attack (meaning, damage points from opponent are not
 ** 			applied). Else, it rolls its defense dice to counter the damage points
 ** 			inflicted by the other Opponents attack.
 ** Parameters:  int damage (returned from Opponent 1's attack function)
 ** Pre-Conditions: total damage points from other Opponent; strength unmodified
 ** Post-Conditions: Vampire strength reduced (attack - (defense + armor))
 **************************************************************************************/
void Vampire::defense(int damage) {
    /*determine if Vampire uses charm defense*/
    bool useCharmDefense = false;
    int charm;

    charm = rand() % 2;

    /*use charm defense*/
    if (charm == 1) {
        useCharmDefense = true;
    }

    /*charm defense initialized. return to user*/
    if (strength > 0 && useCharmDefense) {
        cout << "Vampire Charm Defense! Attack thwarted!" << endl;
        cout << "strength is: " << strength << endl;
        return;
    }

    /*charm defense not used; continue with basic defense function*/
    if (strength > 0 && !useCharmDefense) {
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
            cout << "This Vampire has been removed from combat." << endl;
        } else {
            strength = temp;
            cout << getName() << " strength now = " << strength << endl;
        }

    } else {
        cout << "This Vampire is out of combat." << endl;
    }
}

