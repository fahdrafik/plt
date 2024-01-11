#include "Static_scene.h"
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