#include "Menu.h"
#include "state.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;
using namespace render;
using namespace sf;

Menu::Menu(){

}
Menu::Menu(render::ChoiceMenu *choice, sf::RenderWindow *window, render::Static_scene *scene) {
    this->choice = choice;
    this->window = window;
    this->scene = scene;
    this->deckChoice1 = NoChoice;
    this->deckChoice2 = NoChoice;
}

Menu::~Menu(){

}

bool Menu::getGameInit() const {
    return GameInit;
}

void Menu::setGameInit(bool GameInit) {
    this->GameInit=GameInit;
}

void Menu::setDeckChoice1(state::DeckChoice deckChoice1) {
    this->deckChoice1=deckChoice1;
}

void Menu::setDeckChoice2(state::DeckChoice deckChoice2) {
    this->deckChoice2=deckChoice2;
}

state::DeckChoice Menu::getDeckChoice1() const {
    return deckChoice1;
}

state::DeckChoice Menu::getDeckChoice2() const {
    return deckChoice2;
}

void Menu::run() {
    while (window->isOpen()||GameInit==0)
    {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;

        while (window->pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed) {
                window->close();
            }

            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
                sf::Vector2f mousePosition = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
                switch(scene->getWindow()){
                    case TITLE_SCREEN_WINDOW:
                        choice->handleTitleScreen(mousePosition);
                        break;
                    case MENU_WINDOW:
                        choice->handleMenuScene(mousePosition);
                        break;
                    case PLAYER_1_CHOICE:
                        deckChoice1 = choice->handleDeckChoice1(mousePosition);
                        break;
                    case PLAYER_2_CHOICE:
                        deckChoice2 = choice->handleDeckChoice2(mousePosition);
                        break;
                    case VIEW_CARDS_WINDOW:
                        choice->handleViewCards(mousePosition);
                    case IN_PLAY_WINDOW:
                        if((deckChoice1 != NoChoice)&&(deckChoice2 != NoChoice)){
                            GameInit=1;
                        }
                        break;
                    default:
                        break;
                }
            }
            scene->drawSprite(scene->getWindow(),*window);
        }
    }
}

void Menu::play() {
    cout << "Jouons !!" << endl;
}



