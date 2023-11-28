#include "state.h"

#include <iostream>
#include <vector>

using namespace std;
namespace state {

    Boards::Boards(std::vector<Spells> spells, std::vector<Traps> traps, std::vector<Monsters> monsters,
                   std::vector<Cards> graveyard) {
        this->spells = spells;
        this->traps = traps;
        this->monsters = monsters;
        this->graveyard = graveyard;
    }

    Boards::~Boards() {

    }

    void Boards::attackPosition() {
        std::cout << "attackPosition\n";
    }

    void Boards::defensePosition() {
        cout << "defensePosition\n";
    }

    void Boards::addMonster() {
        cout << "addMonster\n";
    }

    void Boards::removeMonster() {
        cout << "removeMonster\n";
    }

    void Boards::addSpell() {
        cout << "addSpell\n";
    }

    void Boards::removeSpell() {
        cout << "removeSpell\n";
    }

    void Boards::addTrap() {
        cout << "addTrap\n";
    }

    void Boards::removeTrap() {
        cout << "removeTrap\n";
    }

    void Boards::appel() {
        cout << "appel\n";
    }

}