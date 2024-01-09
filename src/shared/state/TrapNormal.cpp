//
// Created by elmoro on 30/12/23.
//

#include "TrapNormal.h"
#include "state.h"

#include <iostream>
#include <vector>

using namespace std;
namespace state {


void TrapNormal::activate(Boards *attackingBoard, Boards *defendingBoard, int index) // TODO ajout pointeur sur card ??
{
    //Is it really a Trap Card we're trying to activate ??
    if (getIdCard() != 95) {  //95 identifies as a Trap apparently
        std::cerr << "Wrong CardType";
    }
    // Knowing that a Trap Card must first be set before being activated we shall test if the Set bool is true
    //Verifying is set and trapParameter is coherent
    if (getSet() && getTrapParameter() == 0) {
        //TODO: get the defending Board and call the appropriate function on it
        // what happens in a normal effect ??
        cout << " Normal Trap executed  !" << endl;
    }
}

void TrapNormal::desactivate(Boards *attackingBoard, Boards *defendingBoard, int index) { // Do we add

    //desactivating means putting back the set tu false

    Boards* DeacativTrap = new Boards;
    std::vector<Traps> DesactivationVector= attackingBoard->getTraps();
    DesactivationVector[index].setSet(false);
    cout << "Deactivation succeeded !" << endl;
    delete DeacativTrap;
}
/*
 * int newAttack = attackingBoard->getMonsterAttack(index)+spellParameter;
    attackingBoard->setMonsterAttack(newAttack);
    cout << "Spell Equipement launched !" << endl;
 */
}