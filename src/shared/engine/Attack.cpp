//
// Created by cornic on 08/01/24.
//

#include "Attack.h"
#include <iostream>
#include <algorithm>


using namespace state;
using namespace std;

namespace engine {
    Attack::Attack(Monsters monster, int attacktype) { //not need for the Monster monster i think
        if (attacktype == 0) {
            //attack on a monster
            if (attackMonster.getDefense() < attackingMonster.getAttack()) {
                printf("attack succesfull");
                //make the monster die
            } else {
                printf("attack not possible");
            }
        }
        if (attacktype == 1) {
            //attack on a player
            //We verify if it's possible in the engine not here, we don't have access to the board
            attackPlayer.looseLifePoints(attackMonster.getAttack());
        }
    }
    Attack::Attack(){}



}