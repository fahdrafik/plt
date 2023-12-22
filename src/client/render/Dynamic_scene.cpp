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

Dynamic_scene::Dynamic_scene(sf::Transform transform, render::Window affected_window) {
    this->affected_window = affected_window;
}
Dynamic_scene::~Dynamic_scene()
{

}
