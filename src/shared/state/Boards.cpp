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