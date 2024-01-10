//
// Created by corte on 1/8/2024.
//
#include "ModifyHand.h"

#include <iostream>
#include <algorithm>


using namespace state;
using namespace std;

namespace engine {
    ModifyHand::ModifyHand() {}





    void ModifyHand::drawCard() {
        if (player.getDeck()->getCardsInDeck().size()==0){
            cout<<"plus de cartes dans le deck"<<endl;
        }
        else{
            player.drawCard();
            cout<<"carte piochée"<<endl;
        }
    }
    void ModifyHand::execute() {}

    void ModifyHand::placeCard() {
        if (ID_card_InHand_selected>= player.getDeck()->getCardsInHand().size()){
            cout<<"index choisit supérieur au nombre de carte dans la main"<<endl;
        }
        else{
            Cards card_in_hand_chosen= player.getDeck()->getCardsInHand()[ID_card_InHand_selected];
            player.placeCard(card_in_hand_chosen.getID());
            cout<<"carte placé"<<endl;

        }
    }

    int ModifyHand::getID_card_InHand_selected() const {
        return this->ID_card_InHand_selected;
    }
    void ModifyHand::setID_card_InHand_selected(int ID_card_InHand_selected) {
        this->ID_card_InHand_selected=ID_card_InHand_selected;
    }

}