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

    Boards::Boards(){}

    Boards::~Boards() {}

    void Boards::attackPosition(int index) {
        monsters[index].setPosition(0);
    }

    void Boards::defensePosition(int index) {
        monsters[index].setPosition(1);
    }

    void Boards::addMonster(state::Monsters monster) {
        if (monsters.size()>5)
        {
            std::cout << "Pas possible d'ajouter plus de monstres !";
        }
        else
        {
            monsters.push_back(monster);
        }
    }

    void Boards::removeMonster(int index) {
        cout << "removeMonster\n";
    }

    void Boards::addSpell(state::Spells spell) {
        int test = spells.size() + traps.size();
        if (test>5)
        {
            std::cout << "Pas possible d'ajouter plus de cartes pièges !";
        }
        else
        {
            spells.push_back(spell);
        }
    }

    void Boards::removeSpell(int index) {
        cout << "removeSpell\n";
    }

    void Boards::addTrap(state::Traps trap) {
        int test = spells.size() + traps.size();
        if (test>5)
        {
            std::cout << "Pas possible d'ajouter plus de cartes pièges !";
        }
        else
        {
            traps.push_back(trap);
        }
    }

    void Boards::removeTrap(int index) {
        cout << "removeTrap\n";
    }

    int Boards::getId() const{
        return id;
    }
    void Boards::setId(int id){
        this->id=id;
    }
    const std::vector<Monsters>& Boards::getMonsters() const{
        return monsters;
    }
    void Boards::setMonsters(const std::vector<Monsters>& monsters){
        this->monsters=monsters;
    }
    const std::vector<Spells>& Boards::getSpells() const{
        return spells;
    }
    void Boards::setSpells(const std::vector<Spells>& spells){
        this->spells=spells;
    }
    const std::vector<Traps>& Boards::getTraps() const{
        return traps;
    }
    void Boards::setTraps(const std::vector<Traps>& traps){
        this->traps=traps;
    }
    const std::vector<Cards>& Boards::getGraveyard() const{
        return graveyard;
    }
    void Boards::setGraveyard(const std::vector<Cards>& graveyard){
        this->graveyard=graveyard;
    }
}
