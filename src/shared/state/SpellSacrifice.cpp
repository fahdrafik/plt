#include "state.h"

#include <iostream>

using namespace std;
using namespace state;

void SpellSacrifice::activate (Boards* attackingBoard, Boards* defendingBoard, int index){
    attackingBoard->removeMonster(index);
    cout << "Spell Sacrifice launched !" << endl;
}
void SpellSacrifice::desactivate (Boards* attackingBoard, Boards* defendingBoard, int index){
}