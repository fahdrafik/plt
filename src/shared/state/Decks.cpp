//
// Created by elmoro on 14/11/23.
//
#include "state.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
using namespace state;
using namespace std ;

Decks::Decks (std::vector<Cards> cardsInDeck) {
    this->cardsInDeck = cardsInDeck;
}

Decks::Decks (int id) {


    if (id==1){
       //deck dragon
        // Open file with read only access
        std::ifstream input;
        input.open("DeckDragon.txt");
        int temp;

        // Check if file was opened, if not then close program
        if (!input)
        {
            std::cout << "Failure to open file -- DeckDragon.txt" << std::endl;
            exit(0);
        }
        else
        {
            std::string line; // Variable used to hold each line.

            while (std::getline(input, line))
            {
                if (line == "monster") {
                    Monsters m;

                    // Lire les informations nécessaires du fichier ou d'où vous les obtenu
                    getline(input, line); //ligne 2 nom
                    m.setName(line);
                    getline(input, line); //ligne 3 attack
                    temp = stoi(line);
                    m.setAttack(temp);
                    getline(input, line); //ligne 4 defense
                    temp = stoi(line);
                    m.setDefense(temp);
                    // Ajouter le monstre au vecteur cardsInDeck
                    cardsInDeck.push_back(m);
                }
                else if (line == "spell")
                {
                    // Lire les informations nécessaires du fichier ou d'où vous les obtenez
                    // ...

                    Spells s;
                    getline(input, line);
                    s.setName(line);
                    getline(input, line);
                    temp = stoi(line);
                    s.setEffect(temp);
                    getline(input, line);
                    temp = stoi(line);
                    s.setSpellParameter(temp);
                    cardsInDeck.push_back(s);
                }
                else if (line == "trap")
                {
                    Traps t;
                    getline(input, line);

                    t.setName(line);
                    getline(input, line);
                    temp = stoi(line);
                    t.setEffect(temp);
                    getline(input, line);
                    temp = stoi(line);
                    t.setTrapParameter(temp);
                    // ... Initialisez les autres attributs selon vos besoins

                    cardsInDeck.push_back(t);
                }
            }
        }
        input.close(); // closes file stream
    }
    if (id==2){
        //deck soldier
    }
    if (id==3){
        //deck synchro
    }

}

void Decks::shuffle () {
    random_shuffle(cardsInDeck.begin(), cardsInDeck.end());
}
void Decks::drawCard (){
    cardsInHand.push_back(cardsInDeck.back());
    cardsInDeck.pop_back();
}
void Decks::addCard (state::Cards card) {
    cardsInDeck.push_back(card);
    random_shuffle(cardsInDeck.begin(), cardsInDeck.end());
}
void Decks::removeCard (int index) {
    cardsInDeck.erase(cardsInDeck.begin() + index);
}