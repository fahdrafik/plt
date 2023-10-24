#include "Cards.h"
#include <iostream>
using namespace std;

Cards::Cards(int idCard, string name, string description, CardTypes type,etat  state) {
    this->idCard = idCard;
    this->name = name;
    this->description = description;
    this->type = type;
    this->state = state;
}
