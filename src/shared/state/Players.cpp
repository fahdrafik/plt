//
// Created by cornic on 07/11/23.
//
#include "state.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;

Players::Players(Decks Deck, Boards Board, TypePlayer type, int lifepoints)
{
    this->deck = deck;
    this->board = board;
    this->lifepoints = lifepoints;
    this->type = type;
}

Players::~Players()
{
}