//
// Created by cornic on 08/01/24.
//
#include "engine.h"
#include <iostream>

#define PLACE_CARD 0
#define ATTACK_W_MONSTER_ON_PLAYER 1
#define ATTACK_W_MONSTER_ON_MONSTER 2

using namespace state;
namespace engine {


    Engine::Engine() {

    }

    Engine::~Engine() {

    }

    void Engine::setPlayer (Players player){ //need to change the arrow so Attack Modidy.... are a specification of Command
        //modifyBoard.setPlayer(player);
        //attack.setPlayer(player);
        //modifyHand.setPlayer(player);
    }
    void Engine::execute_attackMonsterWmonster() {

    }

    void Engine::execute_Place_Card(){}

    int Engine::execute(int status){

        switch (status)
        {
            case PLACE_CARD:
                execute_Place_Card();
                break;
            case ATTACK_W_MONSTER_ON_MONSTER:
                execute_attackMonsterWmonster();
                break;
            default:
                break;
        }

        return 1;
    }

}