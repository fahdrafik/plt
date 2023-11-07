#include "Cards.h"
#include "state.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state; 

Cards::Cards(std::string name, std::string description, CardTypes typeCarte):typeCarte(typeCarte) {
    this->name = name;
}