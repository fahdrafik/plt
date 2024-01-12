//
// Created by elmoro on 31/12/23.
//
#include "TrapNormal.h"
#include "state.h"

#include <iostream>
#include <vector>

using namespace std;
namespace state {


    void TrapReverse::activate(Boards *attackingBoard, Boards *defendingBoard, int index) // TODO ajout pointeur sur card ??
    {
        if (getIdCard() != 95) {  //95 identifies as a Trap apparently
            std::cerr << "Wrong CardType";
        }

        if (getSet() && getTrapParameter() == 3) {

        }
    }

    void TrapReverse::desactivate(Boards *attackingBoard, Boards *defendingBoard, int index) { // Do we add

        //desactivating means putting back the set to false

        Boards *DeacativTrap = new Boards;
        std::vector<Traps> DesactivationVector = attackingBoard->getTraps();
        DesactivationVector[index].setSet(false);
        cout << "Deactivation succeeded !" << endl;
        delete DeacativTrap;
    }
}