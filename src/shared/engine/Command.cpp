//
// Created by corte on 1/8/2024.
//
#include "Command.h"

using namespace engine;
using namespace std;


//Command::Command() {}
Command::Command (state::Players player, state::GameStates state){
    this->player = player;//do we take an existing player or we create one that will stay as the player in run.
    //we take an existing one, like when it will be its turn the command will apply only on him and not on the advesary
    this->state = state;//
}
Command::~Command (){}
/*
void Command::execute (state::Players player, state::GameStates phase){
    //¿What does this class will do? I don´t understand it
    // this class execute a command after creating it, we modify all the parameter we need and then we execute the command normally
}*/

void Command::setPlayer(const state::Players& player){
    this->player = player;
}

void Command::writeJSON (Command* command){}
void Command::readJSON (std::vector<Command*> command){}
// Setters and Getters
