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
        if (attacktype==0){
            //player.attackCard(*getOpponent(),attackingMonster.getID(),defendingMonster.getID());
        }
        else {
            //player.attackPlayer(attackingMonster.getID(),*getOpponent());
        }

    }
}