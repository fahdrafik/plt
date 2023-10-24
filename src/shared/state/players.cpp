#include "players.h"
#include <iostream>
using namespace std;//

Players::Players(int id, GameStatus status, Decks deck, Boards board, int lifepoints){
    this->id=id;
    this->status =status;
    this->decks = deck;
    this->boards = board;
    this->lifepoints = lifepoints;
}
void Players::drawCard (){
    cout<<"drawCard\n";
}
void Players::placeCard (){
    cout<<"placeCard\n";
}
void Players::setSpell (){
    cout<<"setSpell\n";
}
void Players::endTurn (){
    cout<<"endTurn\n";
}
void Players::looseLifePoints (int degat ){
    cout<<"looseLifePoints\n";
}