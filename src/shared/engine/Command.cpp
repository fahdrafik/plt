//
// Created by corte on 1/8/2024.
//
#include "Command.h"

using namespace engine;
using namespace std;

namespace engine {
//Command::Command() {}
    Command::Command(){
        this->player = state::Players();//do we take an existing player or we create one that will stay as the player in run.
        //we take an existing one, like when it will be its turn the command will apply only on him and not on the advesary
        this->oponent = state::Players();
        this->state = state::GameStates();//
        this->board = state::Boards();
    }
    Command::Command(state::Players player, state::Players oponent, state::GameStates state, state::Boards board) {
        this->player = player;//do we take an existing player or we create one that will stay as the player in run.
        //we take an existing one, like when it will be its turn the command will apply only on him and not on the advesary
        this->oponent = oponent;
        this->state = state;//
        this->board = board;
    }

    Command::~Command() {}

/*
void Command::execute (state::Players player, state::GameStates phase){
    //¿What does this class will do? I don´t understand it
    // this class execute a command after creating it, we modify all the parameter we need and then we execute the command normally
}*/

    void Command::setPlayer(const state::Players &player) {
        this->player = player;
    }
    const state::Players& Command::getPlayer() const{
        return this->player;
    }
    const state::Players& Command::getOponent() const{
        return this->oponent;
    }
    void Command::setOponent(const state::Players &oponent) {
        this->oponent = oponent;
    }
    const state::GameStates& Command::getState() const{
        return this->state;
    }
    void Command::setState(const state::GameStates& state){
        this->state = state;
    }
    const state::Boards& Command::getBoard() const{
        return this->board;
    }
    void Command::setBoard(const state::Boards& board){
        this->board = board;
    }
// Setters and Getters
}