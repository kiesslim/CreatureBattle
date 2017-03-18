/*****************************************************************************************
 ** Program Filename:  Medusa.hpp
 ** Author:  Meredith Kiessling
 ** Date:  14.2.2016
 ** Description: Derived from Creature Class- Medusa!
 ** Input:
 ** Output:
 *****************************************************************************************/

#ifndef MEDUSA_HPP_
#define MEDUSA_HPP_

#include "Creature.hpp"

class Medusa: public Creature {
public:
    Medusa();
    virtual ~Medusa();
    int attack(Creature *beast);
    void defense(int damage);
};

#endif /* MEDUSA_HPP_ */
