#include "Calculation.h"
#include <iostream>

using namespace std;
using namespace state;

Calculation::Calculation(int  lifePointsPlayer1, int lifePointsPlayer2, int attackPointsPlayer1, int attackPointsPlayer2, int defensePointsPlayer1, int defensePointsPlayer2) {
    this->lifePointsPlayer1 = lifePointsPlayer1;
    this->lifePointsPlayer2 = lifePointsPlayer2;
    this->attackPointsPlayer1 = attackPointsPlayer1;
    this->attackPointsPlayer2 = attackPointsPlayer2;
    this->defensePointsPlayer1 = defensePointsPlayer1;
    this->defensePointsPlayer2 = defensePointsPlayer2;
}

Calculation::~Calculation ()
{

}

int Calculation::getDefensePointsPlayer1() const{
    return defensePointsPlayer1;
}
int Calculation::getDefensePointsPlayer2() const{
    return defensePointsPlayer2;
}

int Calculation::getAttackPointsPlayer1() const {
    return attackPointsPlayer1;
}
int Calculation::getAttackPointsPlayer2() const {
    return attackPointsPlayer2;
}
const int & Calculation::getLifePointsPlayer1() const {
    return lifePointsPlayer1;
}
int Calculation::getLifePointsPlayer2() const {
    return lifePointsPlayer2;
}
void Calculation::setLifePointsPlayer1(const int & lifePointsPlayer1)
{
    this->lifePointsPlayer1 = lifePointsPlayer1;
}
void Calculation::setLifePointsPlayer2(int lifePointsPlayer2)
{
    this->lifePointsPlayer2 = lifePointsPlayer2;
}
void Calculation::setAttackPointsPlayer1(int attackPointsPlayer1)
{
    this->attackPointsPlayer1 = attackPointsPlayer1;
}
void Calculation::setAttackPointsPlayer2(int attackPointsPlayer2)
{
    this->attackPointsPlayer2 = attackPointsPlayer2;
}
void Calculation::setDefensePointsPlayer1(int defensePointsPlayer1)
{
    this->defensePointsPlayer1 = defensePointsPlayer1;
}
void Calculation::setDefensePointsPlayer2(int defensePointsPlayer2)
{
    this->defensePointsPlayer2 = defensePointsPlayer2;
}
