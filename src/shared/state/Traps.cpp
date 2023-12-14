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
Traps::Traps (int idCard, std::string name, std::string path, CardTypes typeCarte, trapEffect effect,int trapParameter)
: Cards(idCard,name,path,typeCarte),effect(effect),trapParameter(trapParameter){
}
Traps::Traps (std::string name, std::string path, CardTypes typeCarte, trapEffect effect,int trapParameter)
: Cards(name,path,typeCarte),effect(effect),trapParameter(trapParameter){
}

void Traps::setEffect(trapEffect effect){
    this->effect = effect;
}
trapEffect Traps::getEffect() const {
    return effect;
}


void Traps::activate () {

    // Coder une fonction qui determine le cardType en utilisant la methode CardTypes::CardTypes
    // On a un retour de cardType
    cout<< "keep is simple";
}
bool isOn () {
    return true;
}

