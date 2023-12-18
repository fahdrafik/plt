//
// Created by cornic on 07/11/23.
//
#include "state.h"
#include <iostream>
#include <vector>


using namespace state;
using namespace std;


Players::Players(state::Decks Deck, int lifepoints) {
    this->deck = deck;
    this->lifepoints = lifepoints;
}

void Players::drawCard() {
    cout << "You've drawn a Card\n";
}

void Players::placeCard() {
    cout << "You've placed a Card\n";
}

void Players::setSpell() {
    cout << "You've set a Spell\n";
}

void Players::endTurn() {
    cout << "It's your turn\n";
}

void Players::looseLifePoints(int degat) {
    cout << "LifePoints perdus\n";
}