//
// Created by cornic on 09/01/24.
//
#include "ai.h"
#include "state.h"
#include <ctime>

using namespace state;
using namespace std;

namespace ai {
    ai::ai(){
        srand(time(NULL));
        DeckChoice randomChoice = static_cast<DeckChoice>(rand() % 4);
        TypePlayer type = BOT;
        deck = Decks(randomChoice);
        hand = deck.getCardsInHand();
        board= Boards();//
        bot= Players(&board, &deck,8000, type);
    }
    ai::~ai(){}
    void ai::mainPhase(){
        this->bot.drawCard();
        this->hand=this->bot.getCardsInHand();
        int sizeHand=hand.size();

        //placing cards in board either in attac or defense position
        for (int i=0; i<sizeHand; i++){
            if(hand[i].isMonster()){
                state::Monsters monster = dynamic_cast<state::Monsters&>(hand[i]);
                int attack = monster.getAttack();
                int defense = monster.getDefense();

                //set monser in attack or defense
                if(attack<defense){monster.setPosition(true); }
                else if(defense<attack){monster.setPosition(false);}
                this->bot.board->addMonster(monster);
            }
        }
    }
    // Setters and Getters
}