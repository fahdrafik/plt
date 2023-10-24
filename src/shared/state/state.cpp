#include "state.h"
#include <iostream>
using namespace std;

namespace state {
    Decks::Decks{//constructeur

    }
    void Decks::shuffle(){
        cout<<"Shuffle\n";
    }
    void Decks::drawCard(){
        cout<<"drawCard\n";
    }
    void Decks::addCard (){
        cout<<"addCard\n";
    }
    void decks::removeCard (){
        cout<<"removeCard\n"<<;
    }
 /**************************************
 ***************Boards Class*/
   Boards::Boards(){

   }
    void Boards::attackPosition (){

   }
    void Boards::defensePosition (){

   }
    void Boards::addMonster (){

   }
    void Boards::removeMonster (){

   }
    void Boards::addSpell (){

   }
    void Boards::removeSpell (){

   }
    void Boards::addTrap (){

   }
    void Boards::removeTrap (){

   }
    void Boards::appel (){

   }
/************************************************************************************
 * Class Players */
    Players::Players(){

    }
    void Players::drawCard (){

    }
    void Players::placeCard (){

    }
    void Players::setSpell (){

    }
    void Players::endTurn (){

    }
    void Players::looseLifePoints (int degat ){

    }
/************************************************************************************
 * Class CardTypes */
    CardTypes::CardTypes(){

    }
    void CardTypes::isMonster (){

    }
    void CardTypes::isSpell (){

    }
    bool CardTypes::isTrap (){
        return True
    }
/************************************************************************************
 * Class CardTypes */

}