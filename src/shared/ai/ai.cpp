//
// Created by cornic on 09/01/24.
//
#include "ai.h"
#include "state.h"
#include <ctime>

using namespace state;
using namespace std;

namespace ai {
    void mainPhase(Players Bot){
    }
    ai::ai(){
        srand(time(NULL));
        DeckChoice randomChoice = static_cast<DeckChoice>(rand() % 4);
        TypePlayer type = BOT;
        deck = Decks(randomChoice);
        board= Boards();
        bot= Players(&board, &deck,8000, type);
    }
    ai::~ai(){}
    // Setters and Getters
    const state::GameStates& ai::getState() const{}
    void ai::setState(const state::GameStates& state){}
    const state::Players& ai::getBot() const{}
    void ai::setBot(const state::Players& bot){}
}