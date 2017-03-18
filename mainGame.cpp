/*****************************************************************************************
 ** Program Filename:  mainGame.cpp
 ** Author:  Meredith Kiessling
 ** Date:  14.2.2016
 ** Description: Test Driver for Creatures. Takes two user specified creatures and plays
 ** 			Dungeon and Dragons (modified version)
 ** Input: user input
 ** Output: program determines who wins during 1x1 combat
 *****************************************************************************************/

#include<iostream>

#include"mainGame.hpp"

using namespace std;

int main() {

    int userChoice = 0;

    do {
        displayMenu();
        cout << "Please select Opponent 1 from the list." << endl;
        userChoice = getChoice();
        cin.clear();

        Creature *o1; /*opponent 1*/
        Creature *o2; /*opponent 2*/
        o1 = NULL;
        o2 = NULL;

        /*used to create Creature object, pending user input*/
        switch (userChoice) {
        case 1:
            o1 = new Barbarian();
            break;
        case 2:
            o1 = new BlueMen();
            break;
        case 3:
            o1 = new HarryPotter();
            break;
        case 4:
            o1 = new Medusa();
            break;
        case 5:
            o1 = new Vampire();
            break;
        case 6:
            return 0; /*exits program*/
        }

        cout << "Please select Opponent 2 from the list." << endl;
        userChoice = getChoice();
        cin.clear();
        
        /*used to create Creature object, pending user input*/
        switch (userChoice) {
        case 1:
            o2 = new Barbarian();
            break;
        case 2:
            o2 = new BlueMen();
            break;
        case 3:
            o2 = new HarryPotter();
            break;
        case 4:
            o2 = new Medusa();
            break;
        case 5:
            o2 = new Vampire();
            break;
        case 6:
            delete o1;
            return 0; /*exits program*/
        }

        cout << "Opponent 1 is: " << o1->getName() << endl;
        cout << "Opponent 2 is: " << o2->getName() << endl;
        cout << endl;

        int attack = 0;
        int i = 0;

        cout << endl;
        cout << "GAME: " << o1->getName() << " vs. " << o2->getName() << endl;
        cout << endl;

        do {

            cout << "         Round " << ++i << ": " << endl;
            /*opponent 1 fights opponent 2*/
            cout << "Opponent 1, " << o1->getName() << ", attacks " << o2->getName()
                    << "!";
            cout << endl;
            attack = o1->attack(o2);

            o2->defense(attack);

            if (o2->getStrength() == 0 || o1->getStrength() == 0) {
                if (o2->getStrength() == 0) {
                    cout << "GAME OVER: Opponent 2, " << o2->getName()
                            << ", has died in combat." << endl;
                } else {
                    cout << "GAME OVER: Opponent 1, " << o1->getName()
                            << ", has died in combat." << endl;
                }
            } else {
                /*opponent 2 fights opponent 1*/
                cout << "Now Opponent 2, " << o2->getName() << ", attacks "
                        << o1->getName() << "!" << endl;

                attack = o2->attack(o1);

                o1->defense(attack);
            }
        } while (o1->getStrength() != 0 && o2->getStrength() != 0);

        delete o1;
        delete o2;
        cout << endl;

    } while (userChoice != 6);

    return 0;
}


/**************************************************************************************
 ** Function: displayMenu
 ** Description:  prints user options
 ** Parameters:  
 ** Pre-Conditions: 
 ** Post-Conditions: prints menu to screen
**************************************************************************************/

void displayMenu() {
    cout << "       Dungeons & Dragons! \n" << endl;
    cout << "Below are the Creatures available for combat!" << endl;
    cout << "   1.   Barbarian   " << endl;
    cout << "   2.   Blue Men  " << endl;
    cout << "   3.   Harry Potter   " << endl;
    cout << "   4.   Medusa   " << endl;
    cout << "   5.   Vampire   " << endl;
    cout << "   6.   Quit" << endl;
}


/**************************************************************************************
 ** Function: getChoice
 ** Description:  gets user's choice for which program to run
 ** Parameters:  
 ** Pre-Conditions: 
 ** Post-Conditions: takes user to desired program
**************************************************************************************/
int getChoice() {

    int choice;

    cin >> choice;
    while (!cin) {
        cout << "Invalid selection. Enter 1-6. ";
        cin.clear();
        cin.ignore();
        cin >> choice;
    }
    while (choice < 1 || choice > 6) {
        cout << "Invalid selection. Enter 1-6. ";
        cin >> choice;
    }
    cin.clear();
    cin.ignore();

    return choice;
}

