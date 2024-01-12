#include "Static_scene.h"
#include "state.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace state;
using namespace render;
using namespace sf;

Static_scene::Static_scene() {
    this->background_texture =sf::Texture();
    (this->background_texture).loadFromFile("./Images/background.jpg");
    this->background=sf::Sprite();
    (this->background).setTexture(this->background_texture);
    this->changeWindow(TITLE_SCREEN_WINDOW);
    this->indexConsultCards=0;
}
Static_scene::~Static_scene() {
}

sf::Sprite Static_scene::getBackground ()
{
    return background;
}

Dynamic_scene* Static_scene::getDynamic_scene(int index)
{
    if (index >= 0 && index < (int)playerDynamicScene.size()) {
        return playerDynamicScene[index];
    } else {
        return nullptr;
    }
}
void Static_scene::changeWindow (Window new_window)
{
    this->current_window = new_window;
}
render::Window Static_scene::getWindow ()
{
    return current_window;
}

void Static_scene::setTitleScene()
{
    Title_Screen_Texture.push_back(sf::Texture());
    Title_Screen_Texture.back().loadFromFile("./Images/yugioh.png");

    Title_Screen_Texture.push_back(sf::Texture());
    Title_Screen_Texture.back().loadFromFile("./Images/Button_StartGame.png");

    Title_Screen_SP.push_back(sf::Sprite(Title_Screen_Texture[0]));
    Title_Screen_SP.back().setScale(0.4f,0.4f);
    Title_Screen_SP.back().setPosition(400,200);

    Title_Screen_SP.push_back(sf::Sprite(Title_Screen_Texture[1]));
    Title_Screen_SP.back().setScale(1.0f,1.0f);
    Title_Screen_SP.back().setPosition(475,500);
}
void Static_scene::setInGameScene()
{
    In_Game_Texture.push_back(sf::Texture());
    In_Game_Texture.back().loadFromFile("./Images/Deck.png");
    In_Game_Texture.push_back(sf::Texture());
    In_Game_Texture.back().loadFromFile("./Images/Graveyard.png");
    In_Game_Texture.push_back(sf::Texture());
    In_Game_Texture.back().loadFromFile("./Images/Zone.png");
    In_Game_Texture.push_back(sf::Texture());
    In_Game_Texture.back().loadFromFile("./Images/Spells.png");
    In_Game_Texture.push_back(sf::Texture());
    In_Game_Texture.back().loadFromFile("./Images/Monsters.png");
    In_Game_Texture.push_back(sf::Texture());
    In_Game_Texture.back().loadFromFile("./Images/Menu_J1.png");
    In_Game_Texture.push_back(sf::Texture());
    In_Game_Texture.back().loadFromFile("./Images/Menu_J2.png");
    In_Game_Texture.push_back(sf::Texture());
    In_Game_Texture.back().loadFromFile("./Images/Menu_Droit.png");

    /*Dessiner le plateau*/
    /*Placer le Deck des deux joueurs*/
    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[0]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(500,300);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[0]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(500,400);

    /*Placer les cimetières des deux joueurs*/

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[1]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(650,300);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[1]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(650,400);

    /*Placer les cartes de zone des deux joueurs*/

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[2]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(800,300);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[2]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(800,400);

    /*Placer les cinq cartes monstres Joueur 1 */

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[4]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(450,500);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[4]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(550,500);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[4]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(650,500);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[4]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(750,500);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[4]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(850,500);

    /*Placer les cinq cartes monstres Joueur 2 */

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[4]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(450,150);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[4]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(550,150);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[4]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(650,150);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[4]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(750,150);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[4]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(850,150);

    /*Placer les cinq cartes magie Joueur 1 */

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[3]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(450,650);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[3]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(550,650);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[3]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(650,650);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[3]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(750,650);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[3]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(850,650);

    /*Placer les cinq cartes magie Joueur 2 */

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[3]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(450,0);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[3]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(550,0);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[3]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(650,0);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[3]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(750,0);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[3]));
    In_Game_SP.back().setScale(0.5f,0.5f);
    In_Game_SP.back().setPosition(850,0);

    /*Menu à droite et à gauche */
    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[5]));
    In_Game_SP.back().setScale(1.f,1.f);
    In_Game_SP.back().setPosition(0,0);

    In_Game_SP.push_back(sf::Sprite(In_Game_Texture[7]));
    In_Game_SP.back().setScale(1.f,1.f);
    In_Game_SP.back().setPosition(925,0);
}
void Static_scene::setMenuScene()
{
    Menu_Texture.push_back(sf::Texture());
    Menu_Texture.back().loadFromFile("./Images/yugioh.png");

    Menu_Texture.push_back(sf::Texture());
    Menu_Texture.back().loadFromFile("./Images/Button_J1VSJ2.png");

    Menu_Texture.push_back(sf::Texture());
    Menu_Texture.back().loadFromFile("./Images/Button_J1VSAI.png");

    Menu_Texture.push_back(sf::Texture());
    Menu_Texture.back().loadFromFile("./Images/Button_ConsultCards.png");

    Menu_Texture.push_back(sf::Texture());
    Menu_Texture.back().loadFromFile("./Images/Button_QuitGame.png");

    Menu_SP.push_back(sf::Sprite(Menu_Texture[0]));
    Menu_SP.back().setScale(0.4f,0.4f);
    Menu_SP.back().setPosition(375,75);

    Menu_SP.push_back(sf::Sprite(Menu_Texture[1]));
    Menu_SP.back().setScale(1.0f,1.0f);
    Menu_SP.back().setPosition(475,300);

    Menu_SP.push_back(sf::Sprite(Menu_Texture[2]));
    Menu_SP.back().setScale(1.0f,1.0f);
    Menu_SP.back().setPosition(475,425);

    Menu_SP.push_back(sf::Sprite(Menu_Texture[3]));
    Menu_SP.back().setScale(1.0f,1.0f);
    Menu_SP.back().setPosition(475,550);

    Menu_SP.push_back(sf::Sprite(Menu_Texture[4]));
    Menu_SP.back().setScale(1.0f,1.0f);
    Menu_SP.back().setPosition(475,675);
}
void Static_scene::setConsultScene()
{
    Consult_Cards_Texture.push_back(sf::Texture());
    Consult_Cards_Texture.back().loadFromFile("./Images/Right_Arrow.png");

    Consult_Cards_Texture.push_back(sf::Texture());
    Consult_Cards_Texture.back().loadFromFile("./Images/Left_Arrow.png");

    Consult_Cards_Texture.push_back(sf::Texture());
    Consult_Cards_Texture.back().loadFromFile("./Images/Red Eyes Black Dragon.jpg");

    Consult_Cards_Texture.push_back(sf::Texture());
    Consult_Cards_Texture.back().loadFromFile("./Images/Monster Reborn.jpg");

    Consult_Cards_Texture.push_back(sf::Texture());
    Consult_Cards_Texture.back().loadFromFile("./Images/Mirror Force.jpg");

    Consult_Cards_Texture.push_back(sf::Texture());
    Consult_Cards_Texture.back().loadFromFile("./Images/Button_ReturnMainMenu.png");

    /* Flèches pour changer les cartes*/
    Consult_Cards_SP.push_back(sf::Sprite(Consult_Cards_Texture[0]));
    Consult_Cards_SP.back().setScale(0.6f,0.6f);
    Consult_Cards_SP.back().setPosition(1100,300);

    Consult_Cards_SP.push_back(sf::Sprite(Consult_Cards_Texture[1]));
    Consult_Cards_SP.back().setScale(0.6f,0.6f);
    Consult_Cards_SP.back().setPosition(0,300);

    /*Choix des cartes*/
    Consult_Cards_SP.push_back(sf::Sprite(Consult_Cards_Texture[2]));
    Consult_Cards_SP.back().setScale(0.5f,0.5f);
    Consult_Cards_SP.back().setPosition(270,210);

    Consult_Cards_SP.push_back(sf::Sprite(Consult_Cards_Texture[3]));
    Consult_Cards_SP.back().setScale(0.7f,0.7f);
    Consult_Cards_SP.back().setPosition(500,160);

    Consult_Cards_SP.push_back(sf::Sprite(Consult_Cards_Texture[4]));
    Consult_Cards_SP.back().setScale(0.5f,0.5f);
    Consult_Cards_SP.back().setPosition(830,210);

    /* Retour vers le menu principal*/
    Consult_Cards_SP.push_back(sf::Sprite(Consult_Cards_Texture[5]));
    Consult_Cards_SP.back().setScale(1.0f,1.0f);
    Consult_Cards_SP.back().setPosition(490,600);
}

void Static_scene::setPlayerOneChoiceScene (){
    Choice_1_Deck_Texture.push_back(sf::Texture());
    Choice_1_Deck_Texture.back().loadFromFile("./Images/Titre_Choix_J1.png");

    Choice_1_Deck_Texture.push_back(sf::Texture());
    Choice_1_Deck_Texture.back().loadFromFile("./Images/Button_DeckDragon.png");

    Choice_1_Deck_Texture.push_back(sf::Texture());
    Choice_1_Deck_Texture.back().loadFromFile("./Images/Button_DeckSoldier.png");

    Choice_1_Deck_Texture.push_back(sf::Texture());
    Choice_1_Deck_Texture.back().loadFromFile("./Images/Button_DeckSynchro.png");

    Choice_1_Deck_Texture.push_back(sf::Texture());
    Choice_1_Deck_Texture.back().loadFromFile("./Images/Button_ReturnMainMenu.png");

    Choice_1_Deck_SP.push_back(sf::Sprite(Choice_1_Deck_Texture[0]));
    Choice_1_Deck_SP.back().setScale(0.4f,0.4f);
    Choice_1_Deck_SP.back().setPosition(375,75);

    Choice_1_Deck_SP.push_back(sf::Sprite(Choice_1_Deck_Texture[1]));
    Choice_1_Deck_SP.back().setScale(1.0f,1.0f);
    Choice_1_Deck_SP.back().setPosition(475,300);

    Choice_1_Deck_SP.push_back(sf::Sprite(Choice_1_Deck_Texture[2]));
    Choice_1_Deck_SP.back().setScale(1.0f,1.0f);
    Choice_1_Deck_SP.back().setPosition(475,425);

    Choice_1_Deck_SP.push_back(sf::Sprite(Choice_1_Deck_Texture[3]));
    Choice_1_Deck_SP.back().setScale(1.0f,1.0f);
    Choice_1_Deck_SP.back().setPosition(475,550);

    Choice_1_Deck_SP.push_back(sf::Sprite(Choice_1_Deck_Texture[4]));
    Choice_1_Deck_SP.back().setScale(1.0f,1.0f);
    Choice_1_Deck_SP.back().setPosition(475,675);
}
void Static_scene::setPlayerTwoChoiceScene (){
    Choice_2_Deck_Texture.push_back(sf::Texture());
    Choice_2_Deck_Texture.back().loadFromFile("./Images/Titre_Choix_J2.png");

    Choice_2_Deck_Texture.push_back(sf::Texture());
    Choice_2_Deck_Texture.back().loadFromFile("./Images/Button_DeckDragon.png");

    Choice_2_Deck_Texture.push_back(sf::Texture());
    Choice_2_Deck_Texture.back().loadFromFile("./Images/Button_DeckSoldier.png");

    Choice_2_Deck_Texture.push_back(sf::Texture());
    Choice_2_Deck_Texture.back().loadFromFile("./Images/Button_DeckSynchro.png");

    Choice_2_Deck_Texture.push_back(sf::Texture());
    Choice_2_Deck_Texture.back().loadFromFile("./Images/Button_ReturnMainMenu.png");

    Choice_2_Deck_SP.push_back(sf::Sprite(Choice_2_Deck_Texture[0]));
    Choice_2_Deck_SP.back().setScale(0.4f,0.4f);
    Choice_2_Deck_SP.back().setPosition(375,75);

    Choice_2_Deck_SP.push_back(sf::Sprite(Choice_2_Deck_Texture[1]));
    Choice_2_Deck_SP.back().setScale(1.0f,1.0f);
    Choice_2_Deck_SP.back().setPosition(475,300);

    Choice_2_Deck_SP.push_back(sf::Sprite(Choice_2_Deck_Texture[2]));
    Choice_2_Deck_SP.back().setScale(1.0f,1.0f);
    Choice_2_Deck_SP.back().setPosition(475,425);

    Choice_2_Deck_SP.push_back(sf::Sprite(Choice_2_Deck_Texture[3]));
    Choice_2_Deck_SP.back().setScale(1.0f,1.0f);
    Choice_2_Deck_SP.back().setPosition(475,550);

    Choice_2_Deck_SP.push_back(sf::Sprite(Choice_2_Deck_Texture[4]));
    Choice_2_Deck_SP.back().setScale(1.0f,1.0f);
    Choice_2_Deck_SP.back().setPosition(475,675);
}

void Static_scene::init(){
    /*Mise en place des différentes scènes*/
    this->setTitleScene();
    this->setMenuScene();
    this->setInGameScene();
    this->setConsultScene();
    this->setPlayerTwoChoiceScene();
    this->setPlayerOneChoiceScene();
}

void Static_scene::drawSprite (render::Window choix, sf::RenderWindow& window)
{
    switch(choix)
    {
        case MAIN_WINDOW:
            window.clear();
            window.draw(background);
            for (const auto& sprite : Menu_SP) {
                window.draw(sprite);
            }
            window.display();
            break;
        case MENU_WINDOW:
            window.clear();
            window.draw(background);
            for (const auto& sprite : Menu_SP) {
                window.draw(sprite);
            }
            window.display();
            break;
        case IN_PLAY_WINDOW:
            window.clear();
            window.draw(background);
            for (const auto& sprite : In_Game_SP) {
                window.draw(sprite);
            }
            window.display();
            break;
        case TITLE_SCREEN_WINDOW:
            window.clear();
            window.draw(background);
            for (const auto& sprite : Title_Screen_SP) {
                window.draw(sprite);
            }
            window.display();
            break;
        case VIEW_CARDS_WINDOW:
            window.clear();
            window.draw(background);
            for (const auto& sprite : Consult_Cards_SP) {
                window.draw(sprite);
            }
            window.display();
            break;
        case PLAYER_1_CHOICE:
            window.clear();
            window.draw(background);
            for (const auto& sprite : Choice_1_Deck_SP) {
                window.draw(sprite);
            }
            window.display();
            break;
        case PLAYER_2_CHOICE:
            window.clear();
            window.draw(background);
            for (const auto& sprite : Choice_2_Deck_SP) {
                window.draw(sprite);
            }
            window.display();
            break;
        default:
            break;
    }
}

void Static_scene::drawDynamicScene(sf::RenderWindow& window) {
    if(this->getDynamic_scene(Game->getTurn())!=nullptr)
    {
        cout << Game->getTurn() << endl;
        this->getDynamic_scene(Game->getTurn())->displayCardsInHands();
    }
}

// Getters and Setters
const std::vector<sf::Sprite>& Static_scene::getCards_SP() const{
    return Cards_SP;
}
void Static_scene::setCards_SP(const std::vector<sf::Sprite>& Cards_SP){
    this->Cards_SP=Cards_SP;
}
const std::vector<sf::Texture>& Static_scene::getCards_Texture() const{
    return Cards_Texture;
}
void Static_scene::setCards_Texture(const std::vector<sf::Texture>& Cards_Texture){
    this->Cards_Texture=Cards_Texture;
}
const std::vector<sf::Sprite>& Static_scene::getMenu_SP() const{
    return Menu_SP;
}
void Static_scene::setMenu_SP(const std::vector<sf::Sprite>& Menu_SP){
    this->Menu_SP=Menu_SP;
}
const std::vector<sf::Texture>& Static_scene::getMenu_Texture() const{
    return Menu_Texture;
}
void Static_scene::setMenu_Texture(const std::vector<sf::Texture>& Menu_Texture){
    this->Menu_Texture=Menu_Texture;
}
const std::vector<sf::Sprite>& Static_scene::getIn_Game_SP() const{
    return In_Game_SP;
}
void Static_scene::setIn_Game_SP(const std::vector<sf::Sprite>& In_Game_SP){
    this->In_Game_SP=In_Game_SP;
}
const std::vector<sf::Texture>& Static_scene::getIn_Game_Texture() const{
    return In_Game_Texture;
}
void Static_scene::setIn_Game_Texture(const std::vector<sf::Texture>& In_Game_Texture){
    this->In_Game_Texture=In_Game_Texture;
}
const std::vector<sf::Sprite>& Static_scene::getTitle_Screen_SP() const{
    return Title_Screen_SP;
}
void Static_scene::setTitle_Screen_SP(const std::vector<sf::Sprite>& Title_Screen_SP){
    this->Title_Screen_SP=Title_Screen_SP;
}
const std::vector<sf::Texture>& Static_scene::getTitle_Screen_Texture() const{
    return Title_Screen_Texture;
}
void Static_scene::setTitle_Screen_Texture(const std::vector<sf::Texture>& Title_Screen_Texture){
    this->Title_Screen_Texture=Title_Screen_Texture;
}
const std::vector<sf::Sprite>& Static_scene::getConsult_Cards_SP() const{
    return Consult_Cards_SP;
}
void Static_scene::setConsult_Cards_SP(const std::vector<sf::Sprite>& Consult_Cards_SP){
    this->Consult_Cards_SP=Consult_Cards_SP;
}
const std::vector<sf::Texture>& Static_scene::getConsult_Cards_Texture() const{
    return Consult_Cards_Texture;
}
void Static_scene::setConsult_Cards_Texture(const std::vector<sf::Texture>& Consult_Cards_Texture){
    this->Consult_Cards_Texture=Consult_Cards_Texture;
}
const std::vector<sf::Sprite>& Static_scene::getChoice_1_Deck_SP() const{
    return Choice_1_Deck_SP;
}
void Static_scene::setChoice_1_Deck_SP(const std::vector<sf::Sprite>& Choice_1_Deck_SP){
    this->Choice_1_Deck_SP=Choice_1_Deck_SP;
}
const std::vector<sf::Texture>& Static_scene::getChoice_1_Deck_Texture() const{
    return Choice_1_Deck_Texture;
}
void Static_scene::setChoice_1_Deck_Texture(const std::vector<sf::Texture>& Choice_1_Deck_Texture){
    this->Choice_1_Deck_Texture=Choice_1_Deck_Texture;
}
const std::vector<sf::Sprite>& Static_scene::getChoice_2_Deck_SP() const{
    return Choice_2_Deck_SP;
}
void Static_scene::setChoice_2_Deck_SP(const std::vector<sf::Sprite>& Choice_2_Deck_SP){
    this->Choice_2_Deck_SP=Choice_2_Deck_SP;
}
const std::vector<sf::Texture>& Static_scene::getChoice_2_Deck_Texture() const{
    return Choice_2_Deck_Texture;
}
void Static_scene::setChoice_2_Deck_Texture(const std::vector<sf::Texture>& Choice_2_Deck_Texture){
    this->Choice_2_Deck_Texture=Choice_2_Deck_Texture;
}

void Static_scene::setGame(state::GameStates* Game){
    this->Game=Game;
}

void Static_scene::initPlayerDynamicScene(Dynamic_scene* player1ds, Dynamic_scene* player2ds){
    playerDynamicScene.push_back(player1ds);
    playerDynamicScene.push_back(player2ds);
}

int Static_scene::getIndexConsultCards() const{
    return indexConsultCards;
}
void Static_scene::setIndexConsultCards(int indexConsultCards){
    this->indexConsultCards=indexConsultCards;
}
