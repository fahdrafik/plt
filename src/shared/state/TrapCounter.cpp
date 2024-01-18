//
// Created by elmoro on 31/12/23.
//
#include "TrapNormal.h"
#include "state.h"

#include <iostream>
#include <vector>

using namespace std;
namespace state {


    void TrapCounter::activate(state::Boards attackingBoard, state::Boards defendingBoard, int index) // TODO ajout pointeur sur card ?? Ou avoir un indes qui facilite l'accés
    {
        if (getIdCard() != 95) {  //95 identifies as a Trap apparently
            std::cerr << "Wrong CardType";
        }

        if (getSet() && getTrapParameter() == 2) {
            //Let's find which of the defendingBoard Traps is set to know which one to disable

            //get the list of Traps activated
            std::vector<Traps> ActiveTraps= defendingBoard.getTraps();

            for( auto it = ActiveTraps.begin() ; it !=ActiveTraps.end();it++) {
                if (!it->getSet()) {

                    //choose which one to disable 
                    int indexDisable = 1 ;
                    ActiveTraps[indexDisable].setSet(false); //

                }
            }
        }

        }
    }

    void state::TrapCounter::desactivate (state::Boards attackingBoard, state::Boards* defendingBoard, int index) { // Do we add

        //deactivating means putting back the set tu false
        Boards* DeacativTrap = new Boards;
        std::vector<Traps> DeactivationVector= attackingBoard.getTraps();
        DeactivationVector[index].setSet(false);
        cout << "Deactivation succeeded !" << endl;
        delete DeacativTrap;
    }