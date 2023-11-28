//
// Created by cornic on 14/11/23.
//
#include "Traps.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;

Traps::Traps () {//: Cards(int idCard,std::string name, std::string description, CardTypes typeCarte) :typeCarte(typeCarte){
}
Traps::~Traps () {}

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

