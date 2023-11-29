//
// Created by cornic on 14/11/23.
//
#include "Traps.h"
#include "Cards.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;



Traps::Traps ():Cards(){
}
Traps::~Traps () {}
Traps::Traps (int idCard, std::string name, std::string description, CardTypes typeCarte, trapEffect effect)
: Cards(idCard,name,description,typeCarte),effect(effect){}


void Traps::setEffect(trapEffect effect){
    this->effect = effect;
}
trapEffect Traps::getEffect() const {
    return effect;
}
void Traps::activate () {
    cout<< "keep is simple";
}
bool isOn () {
    return true;
}

