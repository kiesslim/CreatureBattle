/*****************************************************************************************
 ** Program Filename:  Creature.hpp
 ** Author:  Meredith Kiessling
 ** Date:  14.2.2016
 ** Description: Base Creature Class- abstract!
 ** Input:
 ** Output:
 *****************************************************************************************/

#ifndef CREATURE_HPP_
#define CREATURE_HPP_
#include"Die.hpp"
#include<string>
using namespace std;

class Creature {

protected:
    int att; /*attack variable NOT used*/
    int def; /*defense variable NOT used*/
    int armor;
    int strength;
    int qAttDie; /*quantity of attack die*/
    int sAttDie; /*sides of attack die*/
    int qDefDie; /*quantity of defense die*/
    int sDefDie; /*sides of defense die*/
    Die *attDie; /*attack dice*/
    Die *defDie; /*defense dice*/
    std::string name; /*creature type*/

public:
    Creature();
    virtual ~Creature();
    Creature(Creature &beast);
    virtual int attack(Creature *beast) = 0;
    virtual void defense(int damage) = 0;
    int getStrength();
    void setStrength(int s);
    Die* getAttDie();
    Die* getDefDie();
    std::string getName();
};

#endif /* CREATURE_HPP_ */
