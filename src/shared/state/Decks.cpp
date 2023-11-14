//
// Created by elmoro on 14/11/23.
//
#include "Players.h"
#include "States.h"
#include <iostream>
#include <vector>

using namespace state;
using namespace std ;

Decks::Decks (std::vector<Cards> cardsInDeck, std::vector<Cards> cardsInHand) {
    this->cardsInDeck = cardsInDeck;
    this->cardsInHand = cardsInHand;
}

void shuffle () {
    cout << "shuffle is done";
}
void drawCard (){
    cout <<"Cards Drawn";
}
void addCard () {
    cout << "Card added ";
}
void removeCard () {
    cout << " Card removed to Player";
}