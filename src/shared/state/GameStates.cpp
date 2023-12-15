//
// Created by cornic on 14/11/23.
//

#include "GameStates.h"
#include "Players.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;

GameStates::GameStates(){

}

void GameStates::init (){
    this->turn=0;
    Players* player = new Players(*deckChosen,50);
    this->createPlayer(*player);
}
void GameStates::incrementTurn (){
    turn++;
}
void GameStates::displayScore (){
}
void GameStates::addPlayer (){
    if (nbPlayers+nbBots<2){
        nbPlayers+=1;
    }

}
void GameStates::addBot (){
    if (nbPlayers+nbBots<2){
        nbBots+=1;
    }
}
void GameStates::deletePlayer (){
    if (nbPlayers>0){
        nbPlayers-=1;
    }
}
void GameStates::createPlayer (Players& obj){

    this->playerList.push_back(&obj);
}

void GameStates::chooseDeck (Decks& obj){
    this->deckChosen= &obj;

}

void GameStates::deleteBot (){
    if (nbBots>0){
        nbPlayers-=1;
    }
}
// Setters and Getters
int GameStates::getTurn() const{
    return turn;
}
void GameStates::setTurn(int turn){
}
const std::vector<Cards*>& GameStates::getCardList() const{
    return cardList;
}
void GameStates::setCardList(const std::vector<Cards*>& cardList){
    this->cardList = cardList;
}
const std::vector<Players*>& GameStates::getPlayerList() const{
    return playerList;
}
void GameStates::setPlayerList(const std::vector<Players*>& playerList){
    this->playerList = playerList;
}