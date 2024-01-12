#include "Dynamic_scene.h"
#include "render.h"
#include "state.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;
using namespace render;
using namespace sf;

Dynamic_scene::Dynamic_scene() {
}

Dynamic_scene::Dynamic_scene (state::Players* player, sf::RenderWindow* window) {
    this->window = window;
    this->player = player;
    font.loadFromFile("Images/Font/04B_19__.TTF");
}
Dynamic_scene::~Dynamic_scene()
{

}

void Dynamic_scene::init(){
    this->initialiseCardsInHands();
    this->initialiseLifePoints();
}

void Dynamic_scene::displayLifePoints (){
    LifePointsText.setString(std::to_string(player->getLifepoints()));
    window->draw(LifePointsText);
}

void Dynamic_scene::initialiseLifePoints (){
    LifePointsText.setFont(font);
    LifePointsText.setCharacterSize(24);
    LifePointsText.setFillColor(sf::Color(255, 165, 0));
    LifePointsText.setString(std::to_string(player->getLifepoints()));
    //sf::FloatRect LifepointsPos = LifePointsText.getLocalBounds();
    LifePointsText.setPosition(0,900);
}

void Dynamic_scene::initialiseCardsInHands(){
    CardsInHands_Texture.push_back(sf::Texture());
    CardsInHands_Texture.back().loadFromFile("./Images/Monsters.png");

    CardsInHands_SP.push_back(sf::Sprite(CardsInHands_Texture[0]));
    CardsInHands_SP.back().setScale(0.5f,0.5f);
    CardsInHands_SP.back().setPosition(100,100);

    CardsInHands_SP.push_back(sf::Sprite(CardsInHands_Texture[0]));
    CardsInHands_SP.back().setScale(0.5f,0.5f);
    CardsInHands_SP.back().setPosition(100,100);

    CardsInHands_SP.push_back(sf::Sprite(CardsInHands_Texture[0]));
    CardsInHands_SP.back().setScale(0.5f,0.5f);
    CardsInHands_SP.back().setPosition(100,100);

    CardsInHands_SP.push_back(sf::Sprite(CardsInHands_Texture[0]));
    CardsInHands_SP.back().setScale(0.5f,0.5f);
    CardsInHands_SP.back().setPosition(100,100);

    CardsInHands_SP.push_back(sf::Sprite(CardsInHands_Texture[0]));
    CardsInHands_SP.back().setScale(0.5f,0.5f);
    CardsInHands_SP.back().setPosition(100,100);

    CardsInHands_SP.push_back(sf::Sprite(CardsInHands_Texture[0]));
    CardsInHands_SP.back().setScale(0.5f,0.5f);
    CardsInHands_SP.back().setPosition(100,100);

    CardsInHands_SP.push_back(sf::Sprite(CardsInHands_Texture[0]));
    CardsInHands_SP.back().setScale(0.5f,0.5f);
    CardsInHands_SP.back().setPosition(100,100);

    CardsInHands_SP.push_back(sf::Sprite(CardsInHands_Texture[0]));
    CardsInHands_SP.back().setScale(0.5f,0.5f);
    CardsInHands_SP.back().setPosition(100,100);

    CardsInHands_SP.push_back(sf::Sprite(CardsInHands_Texture[0]));
    CardsInHands_SP.back().setScale(0.5f,0.5f);
    CardsInHands_SP.back().setPosition(100,100);

    CardsInHands_SP.push_back(sf::Sprite(CardsInHands_Texture[0]));
    CardsInHands_SP.back().setScale(0.5f,0.5f);
    CardsInHands_SP.back().setPosition(100,100);
}

void Dynamic_scene::displayCardsInHands(){

}