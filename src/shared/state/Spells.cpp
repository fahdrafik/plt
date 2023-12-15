
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

Spells::Spells (int idCard, std::string name, std::string path, CardTypes typeCarte, int effect,int spellParameter) :
Cards(idCard,name,path,typeCarte),effect(effect),spellParameter(spellParameter){}

Spells::Spells (std::string name, std::string path, CardTypes typeCarte, int effect,int spellParameter) :
Cards(name,path,typeCarte),effect(effect),spellParameter(spellParameter){}

Spells::~Spells (){ }

// Setters and Getters
void Spells::setEffect(int effect){
    this ->effect = effect;
}
int Spells::getEffect() const{
    return effect;
}

void Spells::setOn(bool On){
    this->On = On;
}
bool Spells::getOn() const{
    return true;
}

int Spells::getSpellParameter() const
{
    return spellParameter;
}
void Spells::setSpellParameter(int spellParameter)
{
    this->spellParameter = spellParameter;
}
