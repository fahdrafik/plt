//
// Created by corte on 1/8/2024.
//
#include "Command.h"

using namespace engine;
using namespace std;

Command::Command (state::Players player, state::GameStates phase){
    this->player = player;//do we take an existing player or we create one that will stay as the player in run.
    this->phase = phase;//
}
Command::~Command (){}
void Command::execute (state::Players player, state::GameStates phase){
    //¿What does this class will do? I don´t understand it
}
void Command::writeJSON (Command* command){}
void Command::readJSON (std::vector<Command*> command){}
// Setters and Getters
