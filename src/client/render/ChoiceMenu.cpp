#include "ChoiceMenu.h"
#include "state.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;
using namespace render;
using namespace sf;

ChoiceMenu::ChoiceMenu() {
}
ChoiceMenu::ChoiceMenu(Static_scene* scene) {
    this->scene=scene;
}
ChoiceMenu::~ChoiceMenu() {
}

void ChoiceMenu::handleMenuScene(sf::Vector2f mousePosition) {
    auto Menu_SP=scene->getMenu_SP();
    if(Menu_SP[1].getGlobalBounds().contains(mousePosition) || Menu_SP[2].getGlobalBounds().contains(mousePosition))
    {
        scene->changeWindow(PLAYER_1_CHOICE);
    }
    else if(Menu_SP[3].getGlobalBounds().contains(mousePosition)){
        scene->changeWindow(VIEW_CARDS_WINDOW);
    }
}

void ChoiceMenu::handleTitleScreen(sf::Vector2f mousePosition) {
    auto Title_Screen_SP=scene->getTitle_Screen_SP();
    if(Title_Screen_SP[1].getGlobalBounds().contains(mousePosition))
    {
        scene->changeWindow(MENU_WINDOW);
    }
}

DeckChoice ChoiceMenu::handleDeckChoice1(sf::Vector2f mousePosition) {
    auto Choice_1_Deck_SP = scene->getChoice_1_Deck_SP();
    if (Choice_1_Deck_SP[1].getGlobalBounds().contains(mousePosition)) {
        cout << "Choix Player 1 : Deck Dragon ! " << endl;
        scene->changeWindow(PLAYER_2_CHOICE);
        return DeckDragon;
    } else if (Choice_1_Deck_SP[2].getGlobalBounds().contains(mousePosition)) {
        cout << "Choix Player 1 : Deck Soldier ! " << endl;
        scene->changeWindow(PLAYER_2_CHOICE);
        return DeckSoldier;
    } else if (Choice_1_Deck_SP[3].getGlobalBounds().contains(mousePosition)) {
        cout << "Choix Player 1 : Deck Synchro ! " << endl;
        scene->changeWindow(PLAYER_2_CHOICE);
        return DeckSynchro;
    } else {
        cout << "Choix Player 1 : Pas de Deck choisi ! " << endl;
        return NoChoice;
    }
}

DeckChoice ChoiceMenu::handleDeckChoice2(sf::Vector2f mousePosition) {
    auto Choice_2_Deck_SP = scene->getChoice_2_Deck_SP();
    if (Choice_2_Deck_SP[1].getGlobalBounds().contains(mousePosition)) {
        cout << "Choix Player 2 : Deck Dragon ! " << endl;
        scene->changeWindow(IN_PLAY_WINDOW);
        return DeckDragon;
    }
    else if(Choice_2_Deck_SP[2].getGlobalBounds().contains(mousePosition))
    {
        cout << "Choix Player 2 : Deck Soldier ! " << endl;
        scene->changeWindow(IN_PLAY_WINDOW);
        return DeckSoldier;
    }
    else if(Choice_2_Deck_SP[3].getGlobalBounds().contains(mousePosition))
    {
        cout << "Choix Player 2 : Deck Synchro ! " << endl;
        scene->changeWindow(IN_PLAY_WINDOW);
        return DeckSynchro;
    }
    else
    {
        cout << "Choix Player 2 : Pas de Deck choisi ! " << endl;
        return NoChoice;
    }
}