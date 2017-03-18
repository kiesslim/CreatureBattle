/*****************************************************************************************
 ** Program Filename:  HarryPotter.hpp
 ** Author:  Meredith Kiessling
 ** Date:  14.2.2016
 ** Description: Derived from Creature Class- Harry Potter!
 ** Input:
 ** Output:
 *****************************************************************************************/
#ifndef HARRYPOTTER_HPP_
#define HARRYPOTTER_HPP_

#include "Creature.hpp"

class HarryPotter: public Creature {

public:
    HarryPotter();
    virtual ~HarryPotter();
    int attack(Creature *beast);
    void defense(int damage);

private:
    bool isFirstLife; /*bool flag used for Harry's 1up!*/
};

#endif /* HARRYPOTTER_HPP_ */
