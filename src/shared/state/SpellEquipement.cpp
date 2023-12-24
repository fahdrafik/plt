#include "state.h"

#include <iostream>

using namespace std;
using namespace state;

void SpellEquipement::activate (Boards* attackingBoard, Boards* defendingBoard, int index){
    int newAttack = attackingBoard->getMonsterAttack(index)+spellParameter;
    attackingBoard->setMonsterAttack(newAttack);
    cout << "Spell Equipement launched !" << endl;
}
void SpellEquipement::desactivate (Boards* attackingBoard, Boards* defendingBoard, int index){
    int newAttack = attackingBoard->getMonsterAttack(index)-spellParameter;
    attackingBoard->setMonsterAttack(newAttack);
}