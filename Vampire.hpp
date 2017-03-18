/*
 * Vampire.hpp
 *
 *  Created on: Feb 10, 2016
 *      Author: meredithkiessling
 */

#ifndef VAMPIRE_HPP_
#define VAMPIRE_HPP_

#include "Creature.hpp"

class Vampire: public Creature {
private:
    int seed;

public:
    Vampire();
    virtual ~Vampire();
    int attack(Creature *beast);
    void defense(int damage);
};

#endif /* VAMPIRE_HPP_ */
