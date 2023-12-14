#include "Monsters.h"
#include <iostream>

using namespace std;
using namespace state;

Monsters::Monsters(int idCard,std::string name, std::string path, CardTypes typeCarte, int effet, int level, int attack, int defense, bool position):
Cards(idCard,name,path,typeCarte){
    this->effet = effet;
    this->level = level;
    this->attack = attack;
    this->defense = defense;
    this->position = position;
}

Monsters::~Monsters () {}

void Monsters::setLevel(int level)
{
    this->level = level;
}
int Monsters::getLevel() const
{
    return level;
}
void Monsters::setAttack(int attack)
{
    this->attack = attack;
}
int Monsters::getAttack() const
{
    return attack;
}
void Monsters::setDefense(int defense)
{
    this->defense = defense;
}
int Monsters::getDefense() const
{
    return defense;
}
void Monsters::setPosition(bool position)
{
    this->position=position;
}
bool Monsters::getPosition() const
{
    return position;
}
void Monsters::setEffet (int effet ) {
    this->effet = effet;
}
int Monsters::getEffet () const
{
    return effet;
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



