//
// Created by cornic on 07/11/23.
//
#include "state.h"
#include "Boards.h"
#include "Decks.h"
#include <iostream>
#include <vector>


using namespace state;
using namespace std;

namespace state {

    int Players::nbPlayers = 0;

    Players::Players(Boards *board, Decks *deck, int lifepoints, TypePlayer type) {
        this->id = nbPlayers;
        nbPlayers++;
        this->board = board;
        this->deck = deck;
        this->lifepoints = lifepoints;
        this->type = type;
        status = PLAYING;
    }

    Players::~Players() {}

    void Players::drawCard() {
        deck->drawCard();
    }

    void Players::initCardInHands() {
        deck->initCardsInHands();
    }

    void Players::shuffle() {
        deck->shuffle();
    }

    void Players::placeCard(int index) {
        switch (deck->getCardInHandType(index)) {
            case TypeMonster:
                board->addMonster(dynamic_cast<state::Monsters &>(deck->getCardInHand(index)));
                break;
            case TypeSpell:
                board->addSpell(dynamic_cast<state::Spells &>(deck->getCardInHand(index)));
                break;
            case TypeTrap:
                board->addTrap(dynamic_cast<state::Traps &>(deck->getCardInHand(index)));
                break;
            default:
                break;
        }
        deck->removeCard(index);
        cout << "You've placed a card : " << endl;
    }

    void Players::looseLifePoints(int degat) {
        if (lifepoints < degat) {
            lifepoints = 0;
            status = LOOSE;
        } else {
            lifepoints = lifepoints - degat;
        }
        cout << "You lost " << degat << " lifepoints !" << endl;
    }

    void Players::attackPlayer(int attackingCardIndex, state::Players *defendingPlayer) {
        auto attackingMonsters = board->getMonsters();
        defendingPlayer->looseLifePoints(attackingMonsters[attackingCardIndex].getAttack());
        if (defendingPlayer->status == LOOSE) {
            this->status = WON;
        }
    }

    void Players::display() {
        cout << "Player ID : " << getId() << endl;
        cout << "Lifepoints : " << getLifepoints() << endl;
        cout << "Deck state : " << endl;
        deck->display();
        cout << "Board state : " << endl;
        board->display();
    }

    void Players::attackCard(state::Players *defendingPlayer, int attackingCardIndex, int defendingCardIndex) {
        int calculDegat;
        int defendingPoints;
        int attackingPoints;

        auto attackingMonsters = board->getMonsters();
        attackingPoints = attackingMonsters[attackingCardIndex].getAttack();

        if (defendingPlayer->board->getMonsterPosition(defendingCardIndex)) { // Carte en mode defense
            defendingPoints = defendingPlayer->board->getMonsterDefense(defendingCardIndex);
            if (defendingPoints > attackingPoints) {
                calculDegat = defendingPoints - attackingPoints;
                this->looseLifePoints(calculDegat);
                if (this->status == LOOSE) {
                    defendingPlayer->status = WON;
                }
            } else {
                defendingPlayer->board->addGraveyard(defendingPlayer->board->getMonster(defendingCardIndex));
                defendingPlayer->board->removeMonster(defendingCardIndex);
            }
        } else { //Carte en mode attaque
            defendingPoints = defendingPlayer->board->getMonsterAttack(defendingCardIndex);
            if (defendingPoints > attackingPoints) {
                calculDegat = defendingPoints - attackingPoints;
                this->looseLifePoints(calculDegat);
                board->addGraveyard(board->getMonster(attackingCardIndex));
                board->removeMonster(attackingCardIndex);
                if (this->status == LOOSE) {
                    defendingPlayer->status = WON;
                }
            } else {
                calculDegat = attackingPoints - defendingPoints;
                defendingPlayer->looseLifePoints(calculDegat);
                defendingPlayer->board->addGraveyard(defendingPlayer->board->getMonster(defendingCardIndex));
                defendingPlayer->board->removeMonster(defendingCardIndex);
                if (defendingPlayer->status == LOOSE) {
                    this->status = WON;
                }
            }
        }
    }



    int Players::getId() const{
        return id;
    }
    void Players::setId(int id){
        this->id = id;
    }
    int Players::getLifepoints() const{
        return lifepoints;
    }
    void Players::setLifepoints(int lifepoints){
        this->lifepoints=lifepoints;
    }
    GameStatus Players::getStatus() const{
        return status;
    }
    void Players::setStatus(GameStatus status){
        this->status=status;
    }
    TypePlayer Players::getType() const{
        return type;
    }
    void Players::setType(TypePlayer type){
        this->type=type;
    }
}