//
// Created by elmoro on 31/12/23.
//
#include "TrapNormal.h"
#include "state.h"

#include <iostream>
#include <vector>

using namespace std;
namespace state {


    void TrapDelete::activate(Boards *attackingBoard, Boards *defendingBoard, int index) // TODO ajout pointeur sur card ??
    {
        if (getIdCard() != 95) {  //95 identifies as a Trap apparently
            std::cerr << "Wrong CardType";
        }

        if (getSet() && getTrapParameter() == 1) {

            //This trap make the attacker delete or send to Graveyard

            // let's delete one of the defendingPlayer's Monster
            int indexToDelete = 3;  //That is random TODO Get the index of the posessions of a Defending_player !!
            std::vector<Monsters> DeletingMons = defendingBoard->getMonsters();
            DeletingMons.erase(DeletingMons.begin() + indexToDelete);
        }
    }

    void TrapDelete::desactivate(Boards *attackingBoard, Boards *defendingBoard, int index) { // Do we add

        //desactivating means putting back the set tu false

        Boards *DeacativTrap = new Boards;
        std::vector<Traps> DesactivVector = attackingBoard->getTraps();
        DesactivVector[index].setSet(false);
        cout << "Deactivation succeeded !" << endl;
        delete DeacativTrap;
    }
}