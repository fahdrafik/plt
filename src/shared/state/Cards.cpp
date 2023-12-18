#include "state.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;

int Cards::nombreDeCartes = 0;

Cards::Cards(int idCard,std::string name, std::string path, CardTypes typeCarte)
:typeCarte(typeCarte) {
    this->idCard = idCard;
    this->name = name;
    this->path = path;
}
// This one is used in Gamestate
Cards::Cards(std::string name, std::string path, CardTypes typeCarte)
        :typeCarte(typeCarte) {
    this->idCard = Cards::nombreDeCartes;
    nombreDeCartes++;
    this->name = name;
    this->path = path;
}

Cards::Cards() : typeCarte(NoType){
    // Pour chacun des type
}

Cards::~Cards()
{
}

const std::string& Cards::getName()const
{
    return name;
}

void Cards::setName(const std::string& name)
{
    this->name = name;
}

const std::string& Cards::getPath() const
{
    return path;
}
void Cards::setPath(const std::string& path)
{
    this->path = path;
}

CardTypes Cards::getTypeCarte() const{
    return typeCarte;
}
void Cards::setTypeCarte(CardTypes typeCarte)
{
    this->typeCarte=typeCarte;
}

int Cards::getIdCard() const
{
    return idCard;
}

void Cards::setIdCard(int idCard)
{
    this->idCard = idCard;
}

