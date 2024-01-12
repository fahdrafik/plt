//
// Created by cornic on 08/01/24.
//
#include "ModifyBoard.h"
#include <cstdlib>

using namespace engine;
using namespace std;

ModifyBoard::ModifyBoard (state::Cards card, state::Boards board){

}
ModifyBoard::ModifyBoard (){}

void ModifyBoard::change_monster_state (state::Monsters monster, state::Boards board){
    int IdCardToModify = monster.getIdCard();
    std::vector<state::Monsters> monsterArray = board.getMonsters();
    int size =monsterArray.size();
    for (int i=0;i<size;i++){
        if (monsterArray[i].getIdCard()==IdCardToModify){
            if (monsterArray[i].getPosition()==true){
                board.getMonsterDefense(i);
            }
            if (monsterArray[i].getPosition()==false){
                board.getMonsterAttack(i);
            }
        }
    }
}
void ModifyBoard::triggerTrap (state::Traps* trap, state::Boards* attackingBoard, state::Boards* defendingBoard, int index){
    //trap->activate(attackingBoard,defendingBoard, index);
    trap->activate();
}

void ModifyBoard::triggerSpell (state::Spells* spell, state::Boards* attackingBoard, state::Boards* defendingBoard, int index) {
    spell->activate(attackingBoard,defendingBoard, index);
}
void ModifyBoard::SendCardZone (state::Cards card, state::Boards board){
    if (card.isMonster()){
        board.addMonster(dynamic_cast<state::Monsters&>(card));
    }
    if (card.isSpell()){
        board.addSpell(dynamic_cast<state::Spells&>(card));
    }
    if (card.isTrap()){
        board.addTrap(dynamic_cast<state::Traps&>(card));
    }
}
