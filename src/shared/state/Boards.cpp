#include "state.h"

#include <iostream>
#include <vector>

using namespace std;
namespace state {

    Boards::Boards(std::vector<Spells> spells, std::vector<Traps> traps, std::vector<Monsters> monsters,std::vector<Cards> graveyard)
     {
        this->spells = spells;
        this->traps = traps;
        this->monsters = monsters;
        this->graveyard = graveyard;
    }

    Boards::Boards() {}
    Boards::~Boards() {}

    void Boards::attackPosition(int index) {
        monsters[index].setPosition(0);
    }

    void Boards::defensePosition(int index) {
        monsters[index].setPosition(1);
    }

    bool Boards::getMonsterPosition(int index){
        return monsters[index].getPosition();
    }
    int Boards::getMonsterAttack(int index){
        return monsters[index].getDefense();
    }
    int Boards::getMonsterDefense(int index){
        return monsters[index].getAttack();
    }
    Monsters Boards::getMonster(int index){
        return monsters[index];
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
            monsters.erase(monsters.begin() + index);
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
        spells.erase(spells.begin() + index);
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
        traps.erase(traps.begin() + index);
    }

    void Boards::getAndRemoveMonsterFromGraveyard (int index){
        int flag=0;
        int size = (int) graveyard.size();

        for (int i = 0 ; i < size ; i++) {
            if(graveyard[i].getTypeCarte()==TypeMonster)
            {
                flag=1;
            }
        }

        if(flag == 1 && monsters.size() < 5){
        this->addMonster(dynamic_cast<state::Monsters&>(graveyard[index]));
        graveyard.erase(graveyard.begin() + index);
        }
        else{
            cout << "Impossible ! No cards in graveyard and/or no room for another monster on the board !" << endl;
        }
    }

    void Boards::addGraveyard(state::Cards card) {
        graveyard.push_back(card);
    }

    int Boards::getMonsterSize() {
        return (int) monsters.size();
    }

    void Boards::display(){
        std::cout << "Monsters in Board : " << endl;
        for(const auto& monster : monsters){
            std::cout<< monster.getName() << endl;
        }
        if (this->monsters.size()==0)
        {
            cout << "None" << endl;
        }
        std::cout << "Traps in Board : " << endl;
        for(const auto& trap : traps){
            std::cout<< trap.getName() << endl;
        }
        if (this->traps.size()==0)
        {
            cout << "None" << endl;
        }
        std::cout << "Spells in Board : " << endl;
        for(const auto& spell : spells){
            std::cout<< spell.getName() << endl;
        }
        if (this->spells.size()==0)
        {
            cout << "None" << endl;
        }
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
