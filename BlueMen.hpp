/*****************************************************************************************
 ** Program Filename:  BlueMen.hpp
 ** Author:  Meredith Kiessling
 ** Date:  14.2.2016
 ** Description: Derived from Creature Class- Blue Men!
 ** Input:
 ** Output:
 *****************************************************************************************/

#ifndef BLUEMEN_HPP_
#define BLUEMEN_HPP_

#include "Creature.hpp"

class BlueMen: public Creature {
public:
    BlueMen();
    virtual ~BlueMen();
    int attack(Creature *beast);
    void defense(int damage);
};

#endif /* BLUEMEN_HPP_ */
