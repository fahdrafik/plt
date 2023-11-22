#include "render.h"
#include "Static_scene.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;
using namespace sf;
using namespace render;

Static_scene::Scene()
{
}
Static_scene::~Scene()
{

}

sf::Sprite Static_scene::getBackground ()
{
    return background;
}
PlayerRenderer* Static_scene::getPlayerRenderer (int index)
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

