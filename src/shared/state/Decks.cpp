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

Decks::Decks (std::vector<Cards> cardsInDeck, std::vector<Cards> cardsInHand) {
    this->cardsInDeck = cardsInDeck;
    this->cardsInHand = cardsInHand;
}

void Decks::shuffle () {
    std::random_shuffle(cardsInDeck.begin(), cardsInDeck.end());
}
void Decks::drawCard (){
    cout <<"Cards Drawn";
}
void Decks::addCard (state::Cards card) {
    cout << "Card added ";
}
void Decks::removeCard (int index) {
    cout << " Card removed to Player";
}