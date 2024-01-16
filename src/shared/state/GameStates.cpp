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
#include <SFML/Graphics.hpp>

using namespace std;
namespace state {

const char *phasesNames[] = {
        "Draw Phase",
        "First Main Phase",
        "Battle Phase",
        "Second Main Phase",
        "End Phase"
};

GameStates::GameStates() {
}
GameStates::~GameStates () {}

void GameStates::init (Players& first, Players& second) {
    playerList.push_back(first);
    playerList.push_back(second);
    nbPlayers = sizeof(playerList);

    this->turn = 0;
    this->nbTurns = 1;

    playerList[0].shuffle();
    playerList[0].initCardInHands();
    playerList[1].shuffle();
    playerList[1].initCardInHands();

    currentPlayer = &playerList[0];
    currentPhase = DrawPhase;
}

void GameStates::changeTurn (){
    turn = !turn;
    currentPlayer = &playerList[turn];
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

    void GameStates::changePhase() {
            switch (currentPhase) {
                case (DrawPhase):
                    currentPhase = FirstMainPhase;
                    break;
                case (FirstMainPhase):
                    currentPhase = BattlePhase;
                    break;
                case (BattlePhase):
                    currentPhase = SecondMainPhase;
                    break;
                case (SecondMainPhase):
                    currentPhase = EndPhase;
                    break;
                case (EndPhase):
                    currentPhase = DrawPhase;
                    break;
            }

    }

    void GameStates::playPhase() {
            cout << "Appuyer A : Poser une carte" << endl;
            cout << "Appuyer B : Activer une carte Magie" << endl;
            cout << "Appuyer C : Changer position d'une carte" << endl;
            cout << "Appuyer R : Passer à la phase suivante" << endl;
            cout << "Appuyer P : Passer son tour" << endl;
            switch(currentPhase)
                {
                    case(DrawPhase):
                        cout << "Beginning of Turn " << nbTurns << endl;
                        currentPlayer->drawCard();
                        cout << "Player " << this->getCurrentPlayerID() << " has drawn a card !" << endl;
                        break;
                    case(FirstMainPhase):
                        this->mainPhase();
                        break;
                    case(BattlePhase):
                        this->battlePhase();
                        break;
                    case(SecondMainPhase):
                        this->mainPhase();
                        break;
                    case(EndPhase):
                        this->changeTurn();
                        cout << "Player " << this->getCurrentPlayerID() << " has ended his tour !"<< endl;
                        break;
                }
    }

    void GameStates::mainPhase() {
        if((this->currentPlayer->getType())==HUMAN) {
            sf::Event event;
            event.type = sf::Event::KeyPressed;
            event.key.code = sf::Keyboard::A;

            cout << "Appuyer A : Poser une carte" << endl;
            cout << "Appuyer B : Activer une carte Magie" << endl;
            cout << "Appuyer C : Changer position d'une carte" << endl;
            cout << "Appuyer R : Passer à la phase suivante" << endl;
            cout << "Appuyer P : Passer son tour" << endl;

            switch (event.key.code) {
                case sf::Keyboard::A:
                    cout << "Poser une carte " << endl;
                    break;
                case sf::Keyboard::B:
                    cout << "Activer une carte Magie" << endl;
                    break;
                case sf::Keyboard::C:
                    cout << "Changer position d'une carte" << endl;
                    break;
                case sf::Keyboard::R:
                    cout << "Phase suivante";
                    break;
                case sf::Keyboard::P:
                    cout << "Passer son tour";
                    currentPhase = SecondMainPhase;
                    break;
                default:
                    break;
            }
        }
        else{

        }
    }

    void GameStates::battlePhase() {
        if((this->currentPlayer->getType())==HUMAN) {
            sf::Event event;
            event.type = sf::Event::KeyPressed;
            event.key.code = sf::Keyboard::R;

            switch (event.key.code)
            {
                case sf::Keyboard::A:
                    cout << "Attaquer une carte" << endl;
                    break;
                case sf::Keyboard::B:
                    cout << "Attaquer joueur" << endl;
                    break;
                case sf::Keyboard::R:
                    cout << "Phase suivante";
                default:
                    break;
            }
        }
        else{

        }
    }

    // Setters and Getters
    bool GameStates::getTurn() const {
        return turn;
    }

    Phases GameStates::getCurrentPhase() const{
        return currentPhase;
    }
    void GameStates::setCurrentPhase(Phases currentPhase){
        this->currentPhase=currentPhase;
    }

    std::string GameStates::getPhaseName(state::Phases phase) {
        return phasesNames[phase];
    }

    GameStatus GameStates::getCurrentPlayerStatus() {
        return currentPlayer->getStatus();
    }

    int GameStates::getCurrentPlayerID() {
        return currentPlayer->getId();
    }
    void GameStates::setTurn(bool turn) {
        this->turn = turn;
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