//
// Created by cornic on 14/11/23.
//

#include "GameStates.h"
#include "Players.h"
#include "Decks.h"
#include "Boards.h"

#include <iostream>
#include <vector>

using namespace std;
namespace state {

GameStates::GameStates() {
}

void GameStates::init() {
    this->turn = 0;
    this->end = false;
    playerList.clear();
    cardList.clear();

    Boards gameBoard;
    Players player1;
    Decks CardsPLayer1;

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
    gameBoard.setGraveyard();



}

void GameStates::incrementTurn() {
}

void GameStates::displayScore() {
}

void GameStates::addPlayer() {
}

void GameStates::addBot() {
}

void GameStates::deletePlayer() {
}

void GameStates::createPlayer() {
}

void GameStates::deleteBot() {
}

// Setters and Getters
int GameStates::getTurn() const {
    return turn;
}

void GameStates::setTurn(int turn) {
}

const std::vector<Cards> &GameStates::getCardList() const {
    return cardList;
}

void GameStates::setCardList(const std::vector<Cards> &cardList) {
    this->cardList = cardList;
}

const std::vector<Players> &GameStates::getPlayerList() const {
    return playerList;
}

void GameStates::setPlayerList(const std::vector<Players> &playerList) {
    this->playerList = playerList;
}

}