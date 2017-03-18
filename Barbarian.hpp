/*****************************************************************************************
 ** Program Filename:  Barbarian.hpp
 ** Author:  Meredith Kiessling
 ** Date:  14.2.2016
 ** Description: Derived from Creature Class- Barbarian BEAST!
 ** Input:
 ** Output:
 *****************************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

class Barbarian: public Creature {

public:
    Barbarian();
    virtual ~Barbarian();
    int attack(Creature *beast);
    void defense(int damage);
};

#endif /* BARBARIAN_HPP_ */
