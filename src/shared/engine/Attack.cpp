//
// Created by cornic on 08/01/24.
//

#include "Attack.h"
#include <iostream>
#include <algorithm>


using namespace state;
using namespace std;

namespace engine {
    Attack::Attack() {}

    void Attack::execute() {
        Players opponent= this->getOpponent();
        Monsters attackingMonster= player.getBoard()->getMonsters()[attackingMonsterID_onBoard];
        Monsters defendingMonster= opponent.getBoard()->getMonsters()[defendingMonsterID_onBoard];

        if (attacktype==0){

            player.attackCard(&opponent,attackingMonster.getID(),defendingMonster.getID());
        }
        else {
            player.attackPlayer(attackingMonster.getID(),&opponent);
        }

    }
}