#include "state.h"

#include <iostream>

using namespace std;
using namespace state;

void SpellRevival::activate (Boards* attackingBoard, Boards* defendingBoard, int index){
    attackingBoard->getAndRemoveMonsterFromGraveyard(index);
    std::cout << "Spell Revival launched !" << endl;
}
void SpellRevival::desactivate (Boards* attackingBoard, Boards* defendingBoard, int index){
}