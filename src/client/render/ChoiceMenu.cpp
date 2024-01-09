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