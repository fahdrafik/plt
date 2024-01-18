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
        Players opponent = this->getOpponent();
        if (attacktype==0){
            player.attackCard(&opponent,attackingMonster.getIdCard(),defendingMonster.getIdCard());
        }
        else {
            player.attackPlayer(attackingMonster.getIdCard(),&opponent);
        }

    }
}