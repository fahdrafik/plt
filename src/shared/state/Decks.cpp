//
// Created by elmoro on 14/11/23.
//
#include "state.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
using namespace state;
using namespace std;

Decks::Decks (std::vector<Cards> cardsInDeck) {
    this->cardsInDeck = cardsInDeck;
}

Decks::~Decks () {
}

Decks::Decks (DeckChoice DeckChoice) {

    //Création Cartes pour Deck Dragon
    Monsters GriffonDelta("Griffon Delta","Images/Deck/Dragon/GriffonDelta.jpg",TypeMonster,0,3,1500,900,0);
    Monsters GolemDragon("Golem Dragon","Images/Deck/Dragon/GolemDragon.jpg",TypeMonster,0,4,200,2000,0);
    Monsters DragonAppat("Dragon Appat","Images/Deck/Dragon/DragonAppât.jpg",TypeMonster,0,2,300,200,0);
    Monsters DragonBlancAuxYeuxBleus("Dragon Blanc Aux Yeux Bleus","Images/Deck/Dragon/DragonBlancAuxYeuxBleus.jpg",TypeMonster,0,8,3000,2500,0);
    Monsters DragonEtoileBrillante("Dragon Etoile Brillante","Images/Deck/Dragon/DragonEtoileBrillante.jpg",TypeMonster,0,4,1900,1000,0);
    Monsters KaiserHippocampe("Kaiser Hippocampe","Images/Deck/Dragon/KaiserHippocampe.jpg",TypeMonster,0,4,1700,1650,0);


    Traps ForceDeMiroir("Force de Miroir","Images/Deck/Dragon/ForceDeMiroir.jpg",TypeTrap,DeleteCard,1);
    Traps AppelDeLEtreHante("Appel De L'Être Hanté","Images/Deck/Dragon/AppelDeLEtreHante.jpg",TypeTrap,RevivalBeforeAttack,1);
    Traps CylindreMagique("Cylindre Magique","Images/Deck/Dragon/CylindreMagique.jpg",TypeTrap,ReturnAttackToSender,0);

    Spells HurlementDargent("Hurlement D'argent","Images/Deck/Dragon/HurlementDargent.jpg",TypeSpell,Revival,1);
    Spells EpeeDesProfondeurs("Epee Des Profondeurs","Images/Deck/Dragon/EpeeDesProfondeurs.jpg",TypeSpell,Equipement,500);
    Spells SacrificeInutile("Sacrifice Inutile","Images/Deck/Dragon/SacrificeInutile.jpg",TypeSpell,Control,0);

    //Création Cartes pour Deck Soldat
    Monsters ChevalierDuCommencent("Chevalier Du Commencent","Images/Deck/Soldats/ChevalierDuCommencent.jpg",TypeMonster,0,4,500,2000,0);
    Monsters ChevalierDuCrepusule("Chevalier Du Commencent","Images/Deck/Soldats/ChevalierDuCrépusule.jpg",TypeMonster,0,4,500,2000,0);
    Monsters ChevalierDuRoi("Chevalier Du Roi","Images/Deck/Soldats/ChevalierDuRoi.jpg",TypeMonster,0,4,1600,1400,0);
    Monsters EmissaireDuChaos("Emissaire Du Chaos","Images/Deck/Soldats/EmissaireDuChaos.jpg",TypeMonster,0,4,1500,0,0);
    Monsters FloraisonDeCendres("Floraison De Cendres","Images/Deck/Soldats/FloraisonDeCendres.jpg",TypeMonster,0,3,0,1800,0);
    Monsters SoldatDuLustreNoir("Soldat Du Lustre Noir","Images/Deck/Soldats/SoldatDuLustreNoir.jpg",TypeMonster,0,8,3000,2500,0);

    Traps SeptOutilDuBandit("Sept Outil Du Bandit","Images/Deck/Soldats/SeptOutilDuBandit.jpg",TypeTrap,DeleteCardLoosingLP,1000);
    Traps PotDeVinDuTempleMaudit("Pot De Vin Du Temple Maudit","Images/Deck/Soldats/PotDeVinDuTempleMaudit.jpg",TypeTrap,DeleteCardLoosingLP,0);

    Spells MonsterReborn("Monster Reborn","Images/Deck/Dragon/MonsterReborn.jpg",TypeSpell,Revival,1);
    Spells BouletsDesTenebres("Boulets Des Tenebres","Images/Deck/Dragon/BouletsDesTenebres.jpg",TypeSpell,Equipement,-1000);
    Spells RenfortDeLarmee("Renfort de L'armée","Images/Deck/Dragon/RenfortDeLarmee.jpg",TypeSpell,Revival,1);

    //Création Cartes pour Deck Synchro
    Monsters AccelSynchronique("Accel Synchronique","Images/Deck/Synchro/AccelSynchronique.jpg",TypeMonster,0,5,500,2100,0);
    Monsters GuerrierDeLaRoute("Guerrier De La Route","Images/Deck/Synchro/GuerrierDeLaRoute.jpg",TypeMonster,0,8,3000,1500,0);
    Monsters RobotBriseur("Robot Briseur","Images/Deck/Synchro/RobotBriseur.jpg",TypeMonster,0,4,1800,1000,0);
    Monsters ServiteurRobot("Serviteur Robot","Images/Deck/Synchro/ServiteurRobot.jpg",TypeMonster,0,4,1500,1000,0);
    Monsters RouteSynchronique("Route Synchronique","Images/Deck/Synchro/RouteSynchronique.jpg",TypeMonster,0,4,1600,800,0);
    Monsters AvionAReaction("Avion A Reaction","Images/Deck/Synchro/AvionAReaction.jpg",TypeMonster,0,1,500,0,0);

    Traps AvertissementDivin("Avertissement Divin","Images/Deck/Synchro/AvertissementDivin.jpg",TypeTrap,DeleteCardLoosingLP,2000);
    Traps TrappeSansFond("Trappe Sans Fond","Images/Deck/Synchro/TrappeSansFond.jpg",TypeTrap,DeleteCardWithTreshold,1500);

    Spells HacheDeFerPorteBonheur("Hache De Fer Porte Bonheur","Images/Deck/Dragon/HacheDeFerPorteBonheur.jpg",TypeSpell,Equipement,500);
    Spells ChangementDeCoeur("Changement De Coeur","Images/Deck/Dragon/ChangementDeCoeur.jpg",TypeSpell,Control,0);

    switch(DeckChoice)
    {
        // Ajout à cardsM, cardsT, cards pour la board
        case DeckDragon:
            //Initialisation Monstres
            for(int i=0 ; i<5 ; i++){
                cardsInDeck.emplace_back(GriffonDelta);
                cardsM.push_back(GriffonDelta);}
            for(int i=0 ; i<5 ; i++){
                cardsInDeck.emplace_back(GolemDragon);}
            for(int i=0 ; i<5 ; i++){
                cardsInDeck.emplace_back(DragonAppat);}
            for(int i=0 ; i<5 ; i++){
                cardsInDeck.emplace_back(DragonEtoileBrillante);}
            for(int i=0 ; i<4 ; i++){
                cardsInDeck.emplace_back(KaiserHippocampe);}
            cardsInDeck.emplace_back(DragonBlancAuxYeuxBleus);

            //Initialisation Pièges
            for(int i=0 ; i<2 ; i++){
                cardsInDeck.emplace_back(ForceDeMiroir);
                cardsT.push_back(ForceDeMiroir);}
            for(int i=0 ; i<2 ; i++){
                cardsInDeck.emplace_back(AppelDeLEtreHante);}
            for(int i=0 ; i<2 ; i++){
                cardsInDeck.emplace_back(CylindreMagique);}

            //Initialisation Magies
            for(int i=0 ; i<3 ; i++){
                cardsInDeck.emplace_back(HurlementDargent);
                cardsS.push_back(HurlementDargent);}
            for(int i=0 ; i<3 ; i++){
                cardsInDeck.emplace_back(EpeeDesProfondeurs);}
            for(int i=0 ; i<3 ; i++){
                cardsInDeck.emplace_back(SacrificeInutile);}

            break;
        case DeckSoldier:
            //Initialisation Monstres
            for(int i=0 ; i<5 ; i++){
                cardsInDeck.emplace_back(ChevalierDuCommencent);}
            for(int i=0 ; i<5 ; i++){
                cardsInDeck.emplace_back(ChevalierDuCrepusule);}
            for(int i=0 ; i<5 ; i++){
                cardsInDeck.emplace_back(FloraisonDeCendres);}
            for(int i=0 ; i<5 ; i++){
                cardsInDeck.emplace_back(EmissaireDuChaos);}
            for(int i=0 ; i<4 ; i++){
                cardsInDeck.emplace_back(ChevalierDuRoi);}
            cardsInDeck.emplace_back(SoldatDuLustreNoir);
            //Initialisation Pièges
            for(int i=0 ; i<2 ; i++){
                cardsInDeck.emplace_back(ForceDeMiroir);}
            for(int i=0 ; i<2 ; i++){
                cardsInDeck.emplace_back(SeptOutilDuBandit);}
            for(int i=0 ; i<2 ; i++){
                cardsInDeck.emplace_back(PotDeVinDuTempleMaudit);}

            //Initialisation Magies
            for(int i=0 ; i<3 ; i++){
                cardsInDeck.emplace_back(MonsterReborn);}
            for(int i=0 ; i<3 ; i++){
                cardsInDeck.emplace_back(BouletsDesTenebres);}
            for(int i=0 ; i<3 ; i++){
                cardsInDeck.emplace_back(RenfortDeLarmee);}

            break;
        case DeckSynchro:
            //Initialisation Monstres
            for(int i=0 ; i<5 ; i++){
                cardsInDeck.emplace_back(AvionAReaction);}
            for(int i=0 ; i<5 ; i++){
                cardsInDeck.emplace_back(RobotBriseur);}
            for(int i=0 ; i<5 ; i++){
                cardsInDeck.emplace_back(ServiteurRobot);}
            for(int i=0 ; i<5 ; i++){
                cardsInDeck.emplace_back(RouteSynchronique);}
            for(int i=0 ; i<4 ; i++){
                cardsInDeck.emplace_back(AccelSynchronique);}
            cardsInDeck.emplace_back(GuerrierDeLaRoute);

            //Initialisation Pièges
            for(int i=0 ; i<2 ; i++){
                cardsInDeck.emplace_back(ForceDeMiroir);}
            for(int i=0 ; i<2 ; i++){
                cardsInDeck.emplace_back(SeptOutilDuBandit);}
            for(int i=0 ; i<2 ; i++){
                cardsInDeck.emplace_back(PotDeVinDuTempleMaudit);}

            //Initialisation Magies
            for(int i=0 ; i<3 ; i++){
                cardsInDeck.emplace_back(MonsterReborn);}
            for(int i=0 ; i<3 ; i++){
                cardsInDeck.emplace_back(HacheDeFerPorteBonheur);}
            for(int i=0 ; i<3 ; i++){
                cardsInDeck.emplace_back(ChangementDeCoeur);}
            break;
        default:
            break;
    }
}

Decks::Decks (int id) {
/*
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
                    getline(input, line);

                    m.setPath(line);

                    cardsInDeck.push_back(m);
                }
                else if (line == "spell")
                {

                    Spells s;
                    getline(input, line); //nom
                    s.setName(line);
                    getline(input, line);
                    temp = stoi(line);
                    //s.setEffect(temp);          //effet
                    getline(input, line);
                    temp = stoi(line);
                    s.setSpellParameter(temp); //spellparameter
                    getline(input, line);//path
                    s.setPath(line);
                    cardsInDeck.push_back(s);
                }
                else if (line == "trap")
                {
                    Traps t;
                    getline(input, line);

                    t.setName(line);
                    getline(input, line);
                    temp = stoi(line);
                    //t.setEffect(temp);
                    getline(input, line);
                    temp = stoi(line);
                    t.setTrapParameter(temp);
                    getline(input, line);
                    t.setPath(line);
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
*/
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

Cards Decks::getCardInHand (int index) {
    return cardsInHand[index];
}

string Decks::getCardInHandName (int index) {
    return cardsInHand[index].getName();
}

CardTypes Decks::getCardInHandType (int index) {
    return cardsInHand[index].getTypeCarte();
}

Cards Decks::getCardInDeck (int index) {
    return cardsInDeck[index];
}

void Decks::removeCardInHand (int index) {
    cardsInHand.erase(cardsInHand.begin() + index);
}

void Decks::display(){
    std::cout << "Cards in the deck:\n";
    for (const auto& card : cardsInDeck) {
        std::cout << card.getName() << endl;
    }
    std::cout << "Cards in hands:\n";
    for(const auto& card : cardsInHand){
        std::cout<< card.getName() << endl;
    }
    if (this->cardsInHand.size()==0)
    {
        cout << "None" << endl;
    }
}
void Decks::initCardsInHands(){
    std::cout << "Initialise cards in Deck\n";
    for (int i=0 ; i<5 ; i++) {
        cardsInHand.push_back(cardsInDeck.back());
        cardsInDeck.pop_back();
    }
}

void Decks::addCardToHand(Cards card) {
    std::cout << "Add Card to Hand\n";
    cardsInHand.push_back(card);
}