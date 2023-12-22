//
// Created by cornic on 14/11/23.
//

#include "state.h"

/*#include "GameStates.h"
#include "Players.h"
#include "Decks.h"
#include "Boards.h"*/

#include <iostream>
#include <vector>

using namespace std;
namespace state {

GameStates::GameStates() {
}

void GameStates::init (Players& first, Players& second) {

    playerList.push_back(&first); //à revoir
    playerList.push_back(&second);
    this->turn=0;



/*
    playerList.push_back(player1);
    //player1.setId();
    player1.setType(HUMAN);
    player1.setStatus(PLAYING);
    player1.setDeck(CardsPLayer1);
    player1.setBoard(gameBoard);
    player1.setLifepoints(1000);

    CardsPLayer1.setId();
    CardsPLayer1.setCardsInDeck();
    CardsPLayer1.setCardsInHand();
    CardsPLayer1.setNumberOfCards();


    gameBoard.setId();
    gameBoard.setMonsters();
    gameBoard.setSpells();
    gameBoard.setTraps();
    gameBoard.setGraveyard();*/




/*
    Players* player = new Players(deckChosen,50,gameBoard,TypePlayer::HUMAN);
    this->createPlayer(player);
    Players* player2 = new Players(deckChosen,50,gameBoard,TypePlayer::HUMAN);
    this->createPlayer(player2);
*/

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
int GameStates::getTurn() const {
    return turn;
}

void GameStates::setTurn(int turn) {
}

const std::vector<Cards*> &GameStates::getCardList() const {
    return cardList;
}

void GameStates::setCardList(const std::vector<Cards*> &cardList) {
    this->cardList = cardList;
}

const std::vector<Players*> &GameStates::getPlayerList() const {
    return playerList;
}

void GameStates::setPlayerList(const std::vector<Players*> &playerList) {
    this->playerList = playerList;
}

}