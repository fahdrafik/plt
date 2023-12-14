
//
// Created by cornic on 14/11/23.
//
#include "Spells.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;

Spells::Spells (){
}

Spells::Spells (int idCard, std::string name, std::string path, CardTypes typeCarte, spellEffect effect) :
Cards(idCard,name,path,typeCarte),effect(effect){}

Spells::Spells (std::string name, std::string path, CardTypes typeCarte, spellEffect effect) :
        Cards(name,path,typeCarte),effect(effect){}

Spells::~Spells (){ }

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
