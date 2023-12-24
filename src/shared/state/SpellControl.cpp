#include "state.h"

#include <iostream>

using namespace std;
using namespace state;

static int flag=0;
static int size;

void SpellControl::activate (Boards* attackingBoard, Boards* defendingBoard, int index){
    if (attackingBoard->getMonsterSize()<5)
    {
        size = attackingBoard->getMonsterSize();
        attackingBoard->addMonster(defendingBoard->getMonster(index));
        defendingBoard->removeMonster(index);
        flag = 1;
        cout << "Spell Control launched !" << endl;
    }else{
        cout << "Impossible to launch ! " << endl;
    }
}
void SpellControl::desactivate (Boards* attackingBoard, Boards* defendingBoard, int index){
    if(flag==1){
        defendingBoard->addMonster(attackingBoard->getMonster(attackingBoard->getMonsterSize()));
        attackingBoard->removeMonster(attackingBoard->getMonsterSize());
        flag = 0;
    }
}