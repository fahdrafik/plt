//
// Created by cornic on 14/11/23.
//

#include "GameStates.h"
#include "Players.h"
#include "Cards.h"
#include "Decks.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;

GameStates::GameStates() {
}

void GameStates::init() {

    this->turn = 0;
    this->cardList = cardList;
    this->playerList = playerList;
    // Init PLayers + attribution lifepoint
    Players player1;
    Boards Dashboard;
    Decks CardsPlayersOne;

    playerList.push_back(player1);
    player1.setId(1);
    player1.setType(HUMAN);
    player1.setStatus(PLAYING);
    player1.setDeck(CardsPlayersOne);
    player1.setBoard(Dashboard);
    player1.setLifepoints(1000);

    // Attributes of Board to be made one
    /*
    Dashboard.setId();
    Dashboard.setMonsters();
    Dashboard.setSpells();
    Dashboard.getGraveyard();
    Dashboard.nb_boards = 1;*/
    // Deck attribute
    CardsPlayersOne.getId();
    CardsPlayersOne.setNumberOfCards(40);
    //CardsPlayersOne.setCardsInHand();
    //CardsPlayersOne.setCardsInDeck();

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

