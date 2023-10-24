#include "Traps.h"
#include <iostream>

using namespace std;

Traps::Traps(trapEffect effect){
    this->effect=effect;
}
void Traps::activate (){
    return true;
}
bool Traps::isOn (){
    return true;
}