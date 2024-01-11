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

void Dynamic_scene::displayLifePoints (){
    LifepointsText.setString(std::to_string(player->getLifepoints()));
    window->draw(LifepointsText);
}

void Dynamic_scene::initialiseLifePoints (){
    LifepointsText.setFont(font);
    LifepointsText.setCharacterSize(24);
    LifepointsText.setFillColor(sf::Color(255, 165, 0));
    LifepointsText.setString(std::to_string(player->getLifepoints()));
    //sf::FloatRect LifepointsPos = LifePointsText.getLocalBounds();
    LifepointsText.setPosition(0,900);
}