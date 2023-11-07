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

int Calculation::getDefensePointsPlayer1() {
    cout << "getDefensePointsPlayer1\n";
    return 0;
}
int Calculation::getDefensePointsPlayer2() {
    cout << "getDefensePointsPlayer2\n";
    return 0;
}

int Calculation::getAttackPointsPlayer1() {
    cout << "getAttackPointsPlayer1\n";
    return 0;
}
int Calculation::getAttackPointsPlayer2() {
    cout << "getAttackPointsPlayer2\n";
    return 0;
}

int Calculation::getLifePointsPlayer1() {
    cout << "getLifePointsPlayer1\n";
    return 0;
}
int Calculation::getLifePointsPlayer2() {
    cout << "getLifePointsPlayer2\n";
    return 0;
}