#include "Static_scene.h"
#include "state.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;
using namespace render;
using namespace sf;

Static_scene::Static_scene() {

}
Static_scene::~Static_scene() {

}

sf::Sprite Static_scene::getBackground ()
{
    return background;
}

PlayerRenderer* getPlayerRenderer (int index)
{

}
void Static_scene::changeWindow (Window new_window)
{
    current_window = new_window;
}
Window Static_scene::getWindow ()
{
    return current_window;
}