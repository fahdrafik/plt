#include "Monsters.h"
#include <iostream>

using namespace std;
using namespace state;

Monsters::Monsters(int effet, int level, int attack, int defense, bool position){
    this->effet = effet;
    this->level = level;
    this->attack = attack;
    this->defense = defense;
    this->position = position;
}
void Monsters::attackCard(Cards card) {
    cout << "attackCard\n";
}

void Monsters::attackPlayer(Players player) {
    cout << "attackPlayer\n";
}

void Monsters::setSpell() {
    cout << "attack\n";
}
int Monsters::getLevel() const
{
    return level;
}
void Monsters::setLevel(int level)
{
    this->level = level;
}

int Monsters::getAttack() const
{
    return attack;
}
void Monsters::setAttack(int attack)
{
    this->attack = attack;
}
int Monsters::getDefense() const
{
    return defense;
}
void Monsters::setDefense(int defense)
{
    this->defense = defense;
}
bool Monsters::getPosition() const
{
    return position;
}
void Monsters::setPosition(bool position)
{
    this->position=position;
}
int Monsters::getEffet () const
{
    return effet;
}
void Monsters::setEffet (int effet)
{
    this->effet=effet;
}