#include <fstream>
#include <iostream>

#include "State.h"
#include "Player.h"
#include <algorithm>


//namespace state
//{




State::State(){}


State::~State(){
    
}

void State::init()
{

}


std::vector<std::shared_ptr<Card>>& State::getCardsList() {
    return cardsList;
}




void State::incrementTurn()
{
    turn++;
}

const int & State::getTurn() const
{
    return turn;
}


void State::displayScore()
{
}

void State::addPlayer()
{
}

void State::addBot(int difficulty)
{
}

void State::deletePlayer()
{
}

void State::createPlayer()
{
}

void State::deleteBot(int difficulty)
{
}

//} // namespace state

