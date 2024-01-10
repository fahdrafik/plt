//
// Created by cornic on 08/01/24.
//
#include "engine.h"
#include <iostream>

#define PLACE_CARD 0
#define ATTACK_W_MONSTER_ON_PLAYER 1
#define ATTACK_W_MONSTER_ON_MONSTER 2
#define CHANGE_TURN 3
#define DRAW_CARD 4
#define CHANGE_MONSTER_STATE 5
#define SEND_GRAVEYARD 6
#define TRIGGER_TRAP_SPELL 7


#define UNSELECT 100

#define SELECT_MONSTER_POS_1 101
#define SELECT_MONSTER_POS_2 102
#define SELECT_MONSTER_POS_3 103
#define SELECT_MONSTER_POS_4 104
#define SELECT_MONSTER_POS_5 105

#define SELECT_MONSTER_POS_6 106
#define SELECT_MONSTER_POS_7 107
#define SELECT_MONSTER_POS_8 108
#define SELECT_MONSTER_POS_9 109
#define SELECT_MONSTER_POS_10 110

#define SELECT_CARD_HAND_1 201
#define SELECT_CARD_HAND_2 202
#define SELECT_CARD_HAND_3 203
#define SELECT_CARD_HAND_4 204
#define SELECT_CARD_HAND_5 205
#define SELECT_CARD_HAND_6 206
#define SELECT_CARD_HAND_7 207
#define SELECT_CARD_HAND_8 208
#define SELECT_CARD_HAND_9 209
#define SELECT_CARD_HAND_10 210


#define CHOOSE_DECK 8 9 10 11 12
using namespace state;
using namespace std;
namespace engine {


    Engine::Engine() {
    }

    Engine::~Engine() {

    }

    void Engine::init(state::GameStates state) {
        current_player= state.getPlayerList()[0];
        opponent_player= state.getPlayerList()[1];

        attack.setState(state);
        modifyBoard.setState(state);
        modifyHand.setState(state);



    }

    void Engine::setPlayer (Players player){
        modifyBoard.setPlayer(player);
        attack.setPlayer(player);
        modifyHand.setPlayer(player);

    }
    void Engine::setOpponent (Players opponent){
        modifyBoard.setOpponent(opponent);
        attack.setOpponent(opponent);
        modifyHand.setOpponent(opponent);

    }

    void Engine::execute_attackMonsterWmonster() {
        attack.setAttacktype(0);
        attack.setPlayer(current_player);
        attack.setOpponent(opponent_player);
        if (attack.getAttackingMonsterID_onBoard()!=5 && attack.getDefendingMonsterID_onBoard()!=5){
            attack.execute();
        }
        else{
            cout <<"Les monstres de défense et d'attaque ne sont pas selectionnés"<< endl;
        }


    }

    void Engine::execute_attackPlayerWmonster() {
        attack.setAttacktype(1);
        attack.setPlayer(current_player);
        attack.setOpponent(opponent_player);
        if (attack.getAttackingMonsterID_onBoard()!=5){
            attack.execute();
        }
        else{
            cout <<"Le monstre d'attaque n'est pas selectionné"<< endl;
        }

    }
    void Engine::execute_Place_Card(){
        if (modifyHand.getID_card_InHand_selected()!=10){
            modifyHand.placeCard();
        }
        else{
            cout<<"pas de carte selectionnée a placer"<<endl;
        }
    }
    void Engine::execute_changeTurn(){
        Players temp = current_player;
        current_player= opponent_player;
        opponent_player = temp;
        this->setOpponent(opponent_player);
        this->setPlayer(current_player);
        state.incrementTurn();

    }

    void Engine::execute_Monster_state() {

    }

    void Engine::execute_send_graveyard() {}
    void Engine::execute_trigger_trap_spell() {}

    int Engine::execute(int status){

        switch (status)
        {
            case PLACE_CARD:
                execute_Place_Card();

                attack.setDefendingMonsterID_onBoard(5);
                attack.setAttackingMonsterID_onBoard(5);
                modifyHand.setID_card_InHand_selected(10);
                break;
            case ATTACK_W_MONSTER_ON_PLAYER:
                execute_attackPlayerWmonster();


                attack.setDefendingMonsterID_onBoard(5);
                attack.setAttackingMonsterID_onBoard(5);
                modifyHand.setID_card_InHand_selected(10);
                break;
            case ATTACK_W_MONSTER_ON_MONSTER:
                execute_attackMonsterWmonster();

                attack.setDefendingMonsterID_onBoard(5);
                attack.setAttackingMonsterID_onBoard(5);
                modifyHand.setID_card_InHand_selected(10);
                break;

            case CHANGE_TURN:
                execute_changeTurn();
                break;
            case DRAW_CARD:

                break;
            case CHANGE_MONSTER_STATE:
                execute_Monster_state();

                attack.setDefendingMonsterID_onBoard(5);
                attack.setAttackingMonsterID_onBoard(5);
                modifyHand.setID_card_InHand_selected(10);
                break;
            case SEND_GRAVEYARD:
                execute_send_graveyard();
                break;
            case TRIGGER_TRAP_SPELL:
                execute_trigger_trap_spell();
                break;

            case SELECT_MONSTER_POS_1  :
                attack.setAttackingMonsterID_onBoard(0);
                break;
            case SELECT_MONSTER_POS_2  :
                attack.setAttackingMonsterID_onBoard(1);
                break;
            case SELECT_MONSTER_POS_3  :
                attack.setAttackingMonsterID_onBoard(2);
                break;
            case SELECT_MONSTER_POS_4  :
                attack.setAttackingMonsterID_onBoard(3);
                break;
            case SELECT_MONSTER_POS_5  :
                attack.setAttackingMonsterID_onBoard(4);
                break;

            case SELECT_MONSTER_POS_6  :
                attack.setDefendingMonsterID_onBoard(0);
                break;
            case SELECT_MONSTER_POS_7  :
                attack.setDefendingMonsterID_onBoard(1);
                break;
            case SELECT_MONSTER_POS_8  :
                attack.setDefendingMonsterID_onBoard(2);
                break;
            case SELECT_MONSTER_POS_9  :
                attack.setDefendingMonsterID_onBoard(3);
                break;
            case SELECT_MONSTER_POS_10 :
                attack.setDefendingMonsterID_onBoard(4);
                break;
            case UNSELECT:
                attack.setDefendingMonsterID_onBoard(5);
                attack.setAttackingMonsterID_onBoard(5);
                modifyHand.setID_card_InHand_selected(10);
                break;
            case SELECT_CARD_HAND_1 :
                modifyHand.setID_card_InHand_selected(0);
                break;
            case SELECT_CARD_HAND_2 :
                modifyHand.setID_card_InHand_selected(1);
                break;
            case SELECT_CARD_HAND_3 :
                modifyHand.setID_card_InHand_selected(2);
                break;
            case SELECT_CARD_HAND_4 :
                modifyHand.setID_card_InHand_selected(3);
                break;
            case SELECT_CARD_HAND_5 :
                modifyHand.setID_card_InHand_selected(4);
                break;
            case SELECT_CARD_HAND_6 :
                modifyHand.setID_card_InHand_selected(5);
                break;
            case SELECT_CARD_HAND_7 :
                modifyHand.setID_card_InHand_selected(6);
                break;
            case SELECT_CARD_HAND_8 :
                modifyHand.setID_card_InHand_selected(7);
                break;
            case SELECT_CARD_HAND_9 :
                modifyHand.setID_card_InHand_selected(8);
                break;
            case SELECT_CARD_HAND_10 :
                modifyHand.setID_card_InHand_selected(9);
                break;
            default:
                break;
        }

        return 1;
    }

}