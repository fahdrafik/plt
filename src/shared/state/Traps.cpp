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
Traps::Traps (int idCard, std::string name, std::string path, CardTypes typeCarte, int effect,int trapParameter)
: Cards(idCard,name,path,typeCarte),effect(effect),trapParameter(trapParameter){
}
Traps::Traps (std::string name, std::string path, CardTypes typeCarte, int effect,int trapParameter)
: Cards(name,path,typeCarte),effect(effect),trapParameter(trapParameter){
}

int Traps::getTrapParameter() const
{
    return trapParameter;
}
void Traps::setTrapParameter(int trapParameter)
{
    this->trapParameter = trapParameter;
}

void Traps::setEffect(int effect){
    this->effect = effect;
}
int Traps::getEffect() const {
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

