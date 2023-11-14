//
// Created by cornic on 14/11/23.
//

#include "GameStates.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;


GameStates::GameStates(){

}

void GameStates::init (){
}
void GameStates::incrementTurn (){
}
void GameStates::displayScore (){
}
void GameStates::addPlayer (){
}
void GameStates::addBot (){
}
void GameStates::deletePlayer (){
}
void GameStates::createPlayer (){
}
void GameStates::deleteBot (){
}
// Setters and Getters
int GameStates::getTurn() const{
    return 3;
}
void GameStates::setTurn(int turn){
}
const std::vector<Cards>& GameStates::getCardList() const{
}
void GameStates::setCardList(const std::vector<Cards>& cardList){
}
const std::vector<Players>& GameStates::getPlayerList() const{
}
void GameStates::setPlayerList(const std::vector<Players>& playerList){
}