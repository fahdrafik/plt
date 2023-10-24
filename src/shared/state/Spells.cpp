#include "Spells.h"
#include <iostream>
using namespace std;//

Spells::Spells(string effect){
    this->effect=effect;
}
bool Spells::isOn(){
    return true;
}