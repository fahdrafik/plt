#include "Static_scene.h"
#include "state.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;
using namespace render;
using namespace sf;

Static_scene::Static_scene() {
    this->background_texture =sf::Texture();
    (this->background_texture).loadFromFile("./Images/background.jpg");
    //Creation and initialisation of the background sprite
    this->background=sf::Sprite();
    (this->background).setTexture(this->background_texture);
    this->changeWindow(TITLE_SCREEN_WINDOW);
}
Static_scene::~Static_scene() {
}

sf::Sprite Static_scene::getBackground ()
{
    return background;
}

PlayerRenderer Static_scene::getPlayerRenderer (int index)
{
    return PlayerRenderers[index];
}
void Static_scene::changeWindow (Window new_window)
{
    this->current_window = new_window;
}
render::Window Static_scene::getWindow ()
{
    return current_window;
}

void Static_scene::setTitleScene()
{
    Title_Screen_Texture.push_back(sf::Texture());
    Title_Screen_Texture.back().loadFromFile("./Images/yugioh.png");

    Title_Screen_Texture.push_back(sf::Texture());
    Title_Screen_Texture.back().loadFromFile("./Images/Bouton_TitleScreen.png");

    Title_Screen_SP.push_back(sf::Sprite(Title_Screen_Texture[0]));
    Title_Screen_SP.back().setScale(0.4f,0.4f);
    Title_Screen_SP.back().setPosition(400,200);

    Title_Screen_SP.push_back(sf::Sprite(Title_Screen_Texture[1]));
    Title_Screen_SP.back().setScale(1.0f,1.0f);
    Title_Screen_SP.back().setPosition(475,500);
}
void Static_scene::setInGameScene()
{
    In_Game_Texture.push_back(sf::Texture());
    In_Game_Texture.back().loadFromFile("./Images/Deck.png");
    In_Game_Texture.push_back(sf::Texture());
    In_Game_Texture.back().loadFromFile("./Images/Graveyard.png");
    In_Game_Texture.push_back(sf::Texture());
    In_Game_Texture.back().loadFromFile("./Images/Zone.png");
    In_Game_Texture.push_back(sf::Texture());
    In_Game_Texture.back().loadFromFile("./Images/Spells.png");
    In_Game_Texture.push_back(sf::Texture());
    In_Game_Texture.back().loadFromFile("./Images/Monsters.png");

    /*Dessiner le plateau*/
    /*Placer le Deck des deux joueurs*/
    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[0]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(500,500);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[0]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(800,500);

    /*Placer les cimetières des deux joueurs*/

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[1]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(500,800);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[1]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(800,800);

    /*Placer les cartes de zone des deux joueurs*/

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[2]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(500,1100);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[2]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(800,1100);

    /*Placer les cinq cartes monstres */

    /*Placer les cinq cartes spells*/

}
void Static_scene::setMenuScene()
{
    Menu_Texture.push_back(sf::Texture());
    Menu_Texture.back().loadFromFile("./Images/yugioh.png");

    Menu_Texture.push_back(sf::Texture());
    Menu_Texture.back().loadFromFile("./Images/Bouton_J1VSJ2.png");

    Menu_Texture.push_back(sf::Texture());
    Menu_Texture.back().loadFromFile("./Images/Bouton_J1VSAI.png");

    Menu_Texture.push_back(sf::Texture());
    Menu_Texture.back().loadFromFile("./Images/Bouton_ConsultCards.png");

    Menu_Texture.push_back(sf::Texture());
    Menu_Texture.back().loadFromFile("./Images/Bouton_JeuQuitter.png");

    Menu_SP.push_back(sf::Sprite(Menu_Texture[0]));
    Menu_SP.back().setScale(0.4f,0.4f);
    Menu_SP.back().setPosition(375,75);

    Menu_SP.push_back(sf::Sprite(Menu_Texture[1]));
    Menu_SP.back().setScale(1.0f,1.0f);
    Menu_SP.back().setPosition(475,300);

    Menu_SP.push_back(sf::Sprite(Menu_Texture[2]));
    Menu_SP.back().setScale(1.0f,1.0f);
    Menu_SP.back().setPosition(475,425);

    Menu_SP.push_back(sf::Sprite(Menu_Texture[3]));
    Menu_SP.back().setScale(1.0f,1.0f);
    Menu_SP.back().setPosition(475,550);

    Menu_SP.push_back(sf::Sprite(Menu_Texture[4]));
    Menu_SP.back().setScale(1.0f,1.0f);
    Menu_SP.back().setPosition(475,675);
}
void Static_scene::setConsultScene()
{
    Consult_Cards_Texture.push_back(sf::Texture());
    Consult_Cards_Texture.back().loadFromFile("./Images/Right_Arrow.png");

    Consult_Cards_Texture.push_back(sf::Texture());
    Consult_Cards_Texture.back().loadFromFile("./Images/Left_Arrow.png");

    Consult_Cards_Texture.push_back(sf::Texture());
    Consult_Cards_Texture.back().loadFromFile("./Images/Red Eyes Black Dragon.jpg");

    Consult_Cards_Texture.push_back(sf::Texture());
    Consult_Cards_Texture.back().loadFromFile("./Images/Monster Reborn.jpg");

    Consult_Cards_Texture.push_back(sf::Texture());
    Consult_Cards_Texture.back().loadFromFile("./Images/Mirror Force.jpg");

    Consult_Cards_Texture.push_back(sf::Texture());
    Consult_Cards_Texture.back().loadFromFile("./Images/Bouton_JeuRetour.png");

    /* Flèches pour changer les cartes*/
    Consult_Cards_SP.push_back(sf::Sprite(Consult_Cards_Texture[0]));
    Consult_Cards_SP.back().setScale(0.6f,0.6f);
    Consult_Cards_SP.back().setPosition(1100,300);

    Consult_Cards_SP.push_back(sf::Sprite(Consult_Cards_Texture[1]));
    Consult_Cards_SP.back().setScale(0.6f,0.6f);
    Consult_Cards_SP.back().setPosition(0,300);

    /*Choix des cartes*/
    Consult_Cards_SP.push_back(sf::Sprite(Consult_Cards_Texture[2]));
    Consult_Cards_SP.back().setScale(0.5f,0.5f);
    Consult_Cards_SP.back().setPosition(270,210);

    Consult_Cards_SP.push_back(sf::Sprite(Consult_Cards_Texture[3]));
    Consult_Cards_SP.back().setScale(0.7f,0.7f);
    Consult_Cards_SP.back().setPosition(500,160);

    Consult_Cards_SP.push_back(sf::Sprite(Consult_Cards_Texture[4]));
    Consult_Cards_SP.back().setScale(0.5f,0.5f);
    Consult_Cards_SP.back().setPosition(830,210);

    /* Retour vers le menu principal*/
    Consult_Cards_SP.push_back(sf::Sprite(Consult_Cards_Texture[5]));
    Consult_Cards_SP.back().setScale(1.0f,1.0f);
    Consult_Cards_SP.back().setPosition(490,600);
}

void Static_scene::drawSprite (render::Window choix, sf::RenderWindow& window)
{
    switch(choix)
    {
        case MAIN_WINDOW:
            window.clear();
            window.draw(background);
            for (const auto& sprite : Menu_SP) {
                window.draw(sprite);
            }
            window.display();
            break;
        case MENU_WINDOW:
            window.clear();
            window.draw(background);
            for (const auto& sprite : Menu_SP) {
                window.draw(sprite);
            }
            window.display();
            break;
        case IN_PLAY_WINDOW:
            window.clear();
            window.draw(background);
            for (const auto& sprite : In_Game_SP) {
                window.draw(sprite);
            }
            window.display();
            break;
        case TITLE_SCREEN_WINDOW:
            window.clear();
            window.draw(background);
            for (const auto& sprite : Title_Screen_SP) {
                window.draw(sprite);
            }
            window.display();
            break;
        case VIEW_CARDS_WINDOW:
            window.clear();
            window.draw(background);
            for (const auto& sprite : Consult_Cards_SP) {
                window.draw(sprite);
            }
            window.display();
        default:
            break;
    }
}