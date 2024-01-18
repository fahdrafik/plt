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
        Players oponent = this->getOponent();
        if (attacktype==0){
            player.attackCard(&oponent,attackingMonster.getIdCard(),defendingMonster.getIdCard());
        }
        else {
            player.attackPlayer(attackingMonster.getIdCard(),&oponent);
        }

    }
}