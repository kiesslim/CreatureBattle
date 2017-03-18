/*****************************************************************************************
 ** Program Filename:  Die.hpp
 ** Author:  Meredith Kiessling
 ** Date:  14.2.2016
 ** Description: Die Class- creates q, dice of n sides and then sums their rolls together
 ** Input: int quantity, int sides
 ** Output: total roll value for q dice with s sides
 *****************************************************************************************/

#ifndef DIE_HPP_
#define DIE_HPP_

class Die {
private:
    int sides;
    int quantity;
    int seed;

public:
    Die();
    Die(int q, int s);
    virtual ~Die();
    int roll();
};

#endif /* DIE_HPP_ */
