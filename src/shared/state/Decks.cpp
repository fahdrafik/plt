#include "Decks.h"
#include <iostream>

using namespace std;
using namespace state;

Decks::Decks(int id, std::vector<Cards> cardsInDeck, std::vector<Cards> cardsInHand, int numberOfCards) {//constructeur
    this->id = id;
    this->cardsInDeck = cardsInDeck;
    this->cardsInHand = cardsInHand;
    this->numberOfCards = numberOfCards;
}
void Decks::shuffle() {
    cout << "Shuffle\n";
}
void Decks::drawCard() {
    cout << "drawCard\n";
}
void Decks::addCard() {
    cout << "addCard\n";
}
void decks::removeCard() {
    cout << "removeCard\n" << ;
}