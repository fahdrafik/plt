//
// Created by elmoro on 14/11/23.
//
#include "state.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace state;
using namespace std ;

Decks::Decks (std::vector<Cards> cardsInDeck) {
    this->cardsInDeck = cardsInDeck;
}

Decks::Decks (int id) {
    if (id==1){
       //deck dragon
    }
    if (id==2){
        //deck soldier
    }
    if (id==3){
        //deck synchro
    }

}

void Decks::shuffle () {
    random_shuffle(cardsInDeck.begin(), cardsInDeck.end());
}
void Decks::drawCard (){
    cardsInHand.push_back(cardsInDeck.back());
    cardsInDeck.pop_back();
}
void Decks::addCard (state::Cards card) {
    cardsInDeck.push_back(card);
    random_shuffle(cardsInDeck.begin(), cardsInDeck.end());
}
void Decks::removeCard (int index) {
    cardsInDeck.erase(cardsInDeck.begin() + index);
}