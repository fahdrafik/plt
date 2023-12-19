//
// Created by cornic on 07/11/23.
//
#include "state.h"
#include <iostream>
#include <vector>


using namespace state;
using namespace std;

namespace state {

    Players::Players(Decks deck, int lifepoints,Boards board,TypePlayer type) {
        this->deck = deck;
        this->lifepoints = lifepoints;
        this->type = type;
        this->board = board;
        status = PLAYING;
    }

    void Players::drawCard() {
        deck.drawCard();
    }

    void Players::placeCard(int index) {
        switch(deck.getCardInHandType(index))
        {
            case TypeMonster:
                board.addMonster(dynamic_cast<state::Monsters&>(deck.getCardInHand(index)));
                break;
            case TypeSpell:
                board.addSpell(dynamic_cast<state::Spells&>(deck.getCardInHand(index)));
                break;
            case TypeTrap:
                board.addTrap(dynamic_cast<state::Traps&>(deck.getCardInHand(index)));
                break;
            default:
                break;
        }
        deck.removeCard(index);
        cout << "You've placed a card : " << endl;
    }

    void Players::looseLifePoints(int degat) {
        if(lifepoints < degat)
        {
            lifepoints = 0;
            status = LOOSE;
        }
        else
        {
            lifepoints = lifepoints - degat;
        }
        cout << "You lost " << degat  << " lifepoints !" << endl;
    }
}