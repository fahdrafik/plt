#include "Monsters.h"
#include <iostream>
using namespace std;

Monsters::Monsters(int effet, int level, int attack, int defense, bool position){
    this->effet = effet;
    this->level = level;
    this->attack = attack;
    this->defense = defense;
    this->position = position;
}
void Monsters::attack (carte c){
    cout<<"attack\n";
}
void Monsters::setSpell (){
    cout<<"attack\n";
}