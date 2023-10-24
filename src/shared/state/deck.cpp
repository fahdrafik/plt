#include "deck.h"
#include <iostream>
using namespace std;

Decks::Decks (int id, Cards *cardsInDeck, Cards *cardsInHand, int numberOfCards){//constructeur
    this->id=id;
    this->cardsInDeck=cardsInDeck;
    this->cardsInHand=cardsInHand;
    this->numberOfCards=numberOfCards;

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