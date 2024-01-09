//
// Created by cornic on 14/11/23.
//
#include "Traps.h"
#include "Cards.h"
#include "GameStates.h"
#include "trapEffect.h"


#include <iostream>
#include <vector>

using namespace std;
using namespace state;

Traps::Traps ():Cards(){
}
Traps::~Traps () {}
Traps::Traps (int idCard, std::string name, std::string path, CardTypes typeCarte, trapEffect effect,int trapParameter)
: Cards(idCard,name,path,typeCarte),effect(effect),trapParameter(trapParameter){

}

//Traps (std::string name, std::string path, CardTypes typeCarte, int trapParameter, bool set);
Traps::Traps(std::string name, std::string path, CardTypes typeCarte, int trapParameter, bool set)
        : state::Cards(name, path, typeCarte) {
    set = false;
}

void Traps::setEffect(trapEffect effect) {
    this->effect = effect;
}

trapEffect Traps::getEffect() const {
    return effect;
}

void Traps::setSet(bool Set) {
    this ->Set = Set;
}

bool Traps::getSet() const {
    return Set;
}

void Traps::setTrapParameter(int trapParameter) {
    this ->trapParameter = trapParameter;
}

int Traps::getTrapParameter() const {
    return trapParameter;
}

