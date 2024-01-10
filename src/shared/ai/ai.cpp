//
// Created by cornic on 09/01/24.
//
#include "ai.h"
using namespace ai;
using namespace state;
using namespace std;

namespace ai{
void ai::run (engine::Engine& Engine){}
void ai::GetCard(engine::ModifyBoard ModifyBoard){}
ai::ai (){}
ai::~ai (){}
// Setters and Getters
const GameStates& ai::getState() const{
    return state;
}
void ai::setState(const GameStates& state){
    this->state=state;
}
}