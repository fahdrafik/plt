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