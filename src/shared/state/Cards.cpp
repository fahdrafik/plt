#include "Cards.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state; 

Cards::Cards(int idCard,std::string name, std::string description, CardTypes typeCarte):typeCarte(typeCarte) {
    this->idCard = idCard;
    this->name = name;
    this->description = description;
}

Cards::Cards() : typeCarte("test"){

}

Cards::~Cards()
{
}

int Cards::getIdCard() const
{
    return idCard;
}

void Cards::setIdCard(int idCard)
{
    this->idCard = idCard;
}

const std::string& Cards::getName()const
{
    return name;
}

void Cards::setName(const std::string& name)
{
    this->name = name;
}

const std::string& Cards::getDescription() const
{
    return description;
}
void Cards::setDescription(const std::string& description)
{
    this->description = description;
}

const CardTypes& Cards::getTypeCarte() const{
    return typeCarte;
}
void Cards::setTypeCarte(const CardTypes& typeCarte)
{
    this->typeCarte=typeCarte;
}