
//
// Created by cornic on 14/11/23.
//
#include "Spells.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;

Spells::Spells (){
    this ->effect = effect;
}
Spells::~Spells (){

}


// Setters and Getters
void Spells::setEffect(spellEffect effect){
    this ->effect = effect;
}
spellEffect Spells::getEffect() const{
    return effect;
}

void Spells::setOn(bool On){
    this->On = On;

}
bool Spells::getOn() const{
    return true;
}
