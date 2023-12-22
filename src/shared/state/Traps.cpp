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


Traps::Traps (std::string name, std::string path, CardTypes typeCarte, trapEffect effect,int trapParameter)
: Cards(name,path,typeCarte),effect(effect),trapParameter(trapParameter){



}

void Traps::setEffect(trapEffect effect){
    this->effect = effect;
}

trapEffect Traps::getEffect() const {
    return effect;
}

void Traps::activate (){ //player, card,

    // On a un retour de cardType
    /*
    if (typeCarte != TypeTrap) {
        cout<< " error Wrong CardType";
        exit(0);
    }
    Cards test()

        switch (trapEffect)
        {

            case NormalTrap:

                break;
            case ContinuousTrap:

                break;
            case Counter:

                break;
            case DeleteCard:
                // accéder à cardlist de la board du playerTaking
                // choix du l'index de la card to delete



                break;
            case DeleteCardWithTreshold:

                break;
            case DeleteCardLoosingLP:

                break;
            case ReturnAttackToSender:

                break;
            case RevivalBeforeAttack:

                break;
        }*/

    cout<< "keep is simple";

    //swtitch case en fonction de l'enum !!
}
bool isOn () {
    return true;
}

