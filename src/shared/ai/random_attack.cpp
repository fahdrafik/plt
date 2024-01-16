//
// Created by cornic on 09/01/24.
//
#include "random_attack.h"
#include "state.h"
#include <cstdlib>
#include <ctime>

using namespace state;
using namespace std;

namespace ai {
    random_attack::random_attack(state::Players* oponent) : ai() {
        oponentsMonster = oponent->board->getMonsters();
        myMonsters =bot.board->getMonsters();
        mySpells =bot.board->getSpells();
        myTraps =bot.board->getTraps();
    }
    random_attack::~random_attack (){}
    void random_attack::attackPhase (state::Players* oponent){
        //this method will attack the oponents monster or lifepoints
        int numbOpMonsters=oponent->deck->cardsM.size();//Number of oponent's monsters

        if (0<this->myMonsters.size()){
            //
            for (int i=0;i<this->myMonsters.size();i++){
                srand(time(0));
                int random_index = rand() % this->oponentsMonster.size();

                if (0<numbOpMonsters){this->bot.attackCard(oponent,random_index,i);}
                else if (0==numbOpMonsters){this->bot.attackPlayer(i,oponent);}

                }
            }
        else if(0<this->mySpells.size()){
            //  I would rather activating a maximum of 2 spells or traps
            // to not run out of spells for next steps
            for (int i=0;i<2;i++){
                srand(time(0));
                int random_index = rand() % this->mySpells.size();
                bot.deck->cardsS[random_index].activate(oponent->board,&this->board,random_index);
            }
        }

        else if(0<this->myTraps.size()){
            for (int i=0;i<2;i++){
                srand(time(0));
                int random_index = rand() % this->mySpells.size();
                bot.deck->cardsT[random_index].activate(&this->board,oponent->board,random_index);
            }
        }

    }
}