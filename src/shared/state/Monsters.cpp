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