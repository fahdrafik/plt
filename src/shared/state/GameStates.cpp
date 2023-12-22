//
// Created by cornic on 14/11/23.
//

#include "state.h"

#include "GameStates.h"
#include "Players.h"
#include "Decks.h"
#include "Boards.h"
#include "Phases.h"

#include <iostream>
#include <vector>

using namespace std;
namespace state {

GameStates::GameStates() {
}
GameStates::~GameStates () {}

void GameStates::init (Players& first, Players& second) {

    playerList.push_back(first); //à revoir
    playerList.push_back(second);
    nbPlayers = sizeof(playerList);

    this->turn = 0;
    currentPlayer = &playerList[0];
    currentPhase = DrawPhase;
}

    void GameStates::changeTurn (){
        if (turn==0) {
            turn = 1;
            currentPlayer = &playerList[1];
        }
        else
        {
            turn =0;
            currentPlayer = &playerList[0];
        }
    }
    void GameStates::incrementTurn (){
        nbTurns++;
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
        this->playerList.push_back(obj);
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
bool GameStates::getTurn() const {
    return turn;
}

void GameStates::changePhase() {
    switch(currentPhase)
    {
        case(DrawPhase):
            currentPhase = FirstMainPhase;
            break;
        case(FirstMainPhase):
            currentPhase = BattlePhase;
            break;
        case(BattlePhase):
            currentPhase = SecondMainPhase;
            break;
        case(SecondMainPhase):
            currentPhase = BattlePhase;
            break;
        case(EndPhase):
            currentPhase = DrawPhase;
            break;
    }
}


void GameStates::setTurn(bool turn) {
}

const std::vector<Cards*> &GameStates::getCardList() const {
    return cardList;
}

void GameStates::setCardList(const std::vector<Cards*> &cardList) {
    this->cardList = cardList;
}

const std::vector<Players>& GameStates::getPlayerList() const {
    return playerList;
}

void GameStates::setPlayerList(const std::vector<Players>& playerList) {
    this->playerList = playerList;
}

}