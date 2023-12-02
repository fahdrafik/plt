#include <iostream>
#include <vector>
#include <cstring>
#include <string>

#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API
#define BOOST_TEST_MODULE ModuleTest
#include <boost/test/included/unit_test.hpp>

#define BOOST_TEST_DYN_LINK

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include <state.h>
#include <render.h>

using namespace std;
using namespace state;
using namespace render;

int main(int argc,char* argv[])
{

    if (argc == 1)
    {
        cout << "Hello World from Cergy !" << endl;
    }
    else if (strcmp(argv[1], "hello") == 0)
    {
        cout << "Ca fonctionne ENFIN !!!!" << endl;
    }
    else if (strcmp(argv[1], "state") == 0)
    {
        cout << "Tests" << endl;
        return boost::unit_test::unit_test_main(init_unit_test, argc, argv);
    }
    else if (strcmp(argv[1], "render") == 0)
    {
        cout << "Render" << endl;

        /*Création de la scène*/
        Static_scene scene;

        /*Création de la fenètre*/

        sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Yu-Gi-Oh!");
        sf::Vector2i windowPosition(
                sf::VideoMode::getDesktopMode().width / 2 - window.getSize().x / 2,
                sf::VideoMode::getDesktopMode().height / 2 - window.getSize().y / 2
        );
        window.setPosition(windowPosition);


        /*Ecran titre*/
        /*Titre*/
        sf::Sprite titleSprite;
        sf::Texture titleTexture;
        titleTexture.loadFromFile("./Images/yugioh.png");
        titleSprite.setTexture(titleTexture);
        titleSprite.setScale(0.4f,0.4f);
        titleSprite.setPosition(400,200);
        /*Bouton de l'écran titre*/
        sf::Sprite Button_TitleScreenSp;
        sf::Texture Button_TitleScreenTx;
        Button_TitleScreenTx.loadFromFile("./Images/Bouton_TitleScreen.png");
        Button_TitleScreenSp.setTexture(Button_TitleScreenTx);
        Button_TitleScreenSp.setScale(1.0f,1.0f);
        Button_TitleScreenSp.setPosition(475,500);

        /*Menu du jeu*/
        /*Titre du jeu*/
        sf::Sprite MenuSprite;
        MenuSprite.setTexture(titleTexture);
        MenuSprite.setScale(0.4f,0.4f);
        MenuSprite.setPosition(375,75);

        sf::Sprite Button_J1VSJ2Sp;
        sf::Texture Button_J1VSJ2Tx;
        Button_J1VSJ2Tx.loadFromFile("./Images/Bouton_J1VSJ2.png");
        Button_J1VSJ2Sp.setTexture(Button_J1VSJ2Tx);
        Button_J1VSJ2Sp.setScale(1.0f,1.0f);
        Button_J1VSJ2Sp.setPosition(475,300);

        sf::Sprite Button_J1VSAISp;
        sf::Texture Button_J1VSAITx;
        Button_J1VSAITx.loadFromFile("./Images/Bouton_J1VSAI.png");
        Button_J1VSAISp.setTexture(Button_J1VSAITx);
        Button_J1VSAISp.setScale(1.0f,1.0f);
        Button_J1VSAISp.setPosition(475,425);

        sf::Sprite Button_ConsultCardsSp;
        sf::Texture Button_ConsultCardsTx;
        Button_ConsultCardsTx.loadFromFile("./Images/Bouton_ConsultCards.png");
        Button_ConsultCardsSp.setTexture(Button_ConsultCardsTx);
        Button_ConsultCardsSp.setScale(1.0f,1.0f);
        Button_ConsultCardsSp.setPosition(475,550);

        sf::Sprite Button_JeuQuitterSp;
        sf::Texture Button_JeuQuitterTx;
        Button_JeuQuitterTx.loadFromFile("./Images/Bouton_JeuQuitter.png");
        Button_JeuQuitterSp.setTexture(Button_JeuQuitterTx);
        Button_JeuQuitterSp.setScale(1.0f,1.0f);
        Button_JeuQuitterSp.setPosition(475,675);

        /*En cours de jeu : vue du premier joueur*/

        sf::Sprite DeckSp1;
        sf::Sprite DeckSp2;
        sf::Texture DeckTx;
        DeckTx.loadFromFile("./Images/Deck.png");
        DeckSp1.setTexture(DeckTx);
        DeckSp2.setTexture(DeckTx);

        DeckSp1.setScale(1.0f,1.0f);
        DeckSp1.setPosition(475,675);
        DeckSp2.setScale(1.0f,1.0f);
        DeckSp2.setPosition(475,675);

        sf::Sprite GraveyardSp1;
        sf::Sprite GraveyardSp2;
        sf::Texture GraveyardTx;
        GraveyardTx.loadFromFile("./Images/Graveyard.png");
        GraveyardSp1.setTexture(GraveyardTx);
        GraveyardSp2.setTexture(GraveyardTx);

        GraveyardSp1.setScale(0.2f,0.2f);
        GraveyardSp1.setPosition(475,675);
        GraveyardSp2.setScale(0.2f,0.2f);
        GraveyardSp2.setPosition(475,675);

        sf::Sprite MonstersSp1;
        sf::Sprite MonstersSp2;
        sf::Texture MonstersTx;
        Button_JeuQuitterTx.loadFromFile("./Images/Monsters.png");
        MonstersSp1.setTexture(MonstersTx);
        MonstersSp2.setTexture(MonstersTx);

        MonstersSp1.setScale(1.0f,1.0f);
        MonstersSp1.setPosition(475,675);
        MonstersSp2.setScale(1.0f,1.0f);
        MonstersSp2.setPosition(475,675);

        /*En cours de jeu : vue du deuxième joueur*/

        /*Menu Pause du jeu */

        /*Menu : Consultation des cartes*/
        sf::Sprite Right_Arrow;
        sf::Texture Right_Arrow_Tx;
        Right_Arrow_Tx.loadFromFile("./Images/Right_Arrow.png");
        Right_Arrow.setTexture(Right_Arrow_Tx);
        Right_Arrow.setScale(0.6f,0.6f);
        Right_Arrow.setPosition(1100,300);

        sf::Sprite Left_Arrow;
        sf::Texture Left_Arrow_Tx;
        Left_Arrow_Tx.loadFromFile("./Images/Left_Arrow.png");
        Left_Arrow.setTexture(Left_Arrow_Tx);
        Left_Arrow.setScale(0.6f,0.6f);
        Left_Arrow.setPosition(0,300);

        sf::Sprite Card1;
        sf::Sprite Card2;
        sf::Sprite Card3;
        sf::Texture Card1Tx;
        Card1Tx.loadFromFile("./Images/Red Eyes Black Dragon.jpg");
        Card1.setTexture(Card1Tx);
        Card1.setScale(0.5f,0.5f);
        Card1.setPosition(270,210);
        sf::Texture Card2Tx;
        Card2Tx.loadFromFile("./Images/Mirror Force.jpg");
        Card2.setTexture(Card2Tx);
        Card2.setScale(0.7f,0.7f);
        Card2.setPosition(500,160);
        sf::Texture Card3Tx;
        Card3Tx.loadFromFile("./Images/Monster Reborn.jpg");
        Card3.setTexture(Card3Tx);
        Card3.setScale(0.5f,0.5f);
        Card3.setPosition(830,210);

        sf::Sprite Button_JeuRetourSp;
        sf::Texture Button_JeuRetourTx;
        Button_JeuRetourTx.loadFromFile("./Images/Bouton_JeuRetour.png");
        Button_JeuRetourSp.setTexture(Button_JeuRetourTx);
        Button_JeuRetourSp.setScale(1.0f,1.0f);
        Button_JeuRetourSp.setPosition(490,600);

        while (window.isOpen())
        {
            // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
            sf::Event event;

            while (window.pollEvent(event))
            {
                // évènement "fermeture demandée" : on ferme la fenêtre
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed)
                {
                        if (event.key.code == sf::Keyboard::A) {
                            std::cout << "Menu principal" << std::endl;
                            scene.changeWindow(MAIN_WINDOW);
                        }
                        else if (event.key.code == sf::Keyboard::B) {
                            std::cout << "Phase de jeu : J1" << std::endl;
                            scene.changeWindow(MENU_WINDOW);
                        }
                        else if (event.key.code == sf::Keyboard::C) {
                            std::cout << "Phase de jeu : J2" << std::endl;
                            scene.changeWindow(IN_PLAY_WINDOW);
                        }
                        else if (event.key.code == sf::Keyboard::D) {
                            std::cout << "Consultation des cartes" << std::endl;
                            scene.changeWindow(VIEW_CARDS_WINDOW);
                        }
                        else if (event.key.code == sf::Keyboard::E){
                            std::cout << "Ecran titre"  << std::endl;
                            scene.changeWindow(TITLE_SCREEN_WINDOW);
                        }
                }

                switch(scene.getWindow())
                {
                    case MAIN_WINDOW:
                        window.clear();
                        window.draw(scene.getBackground());
                        window.draw(MenuSprite);
                        window.draw(Button_ConsultCardsSp);
                        window.draw(Button_J1VSAISp);
                        window.draw(Button_J1VSJ2Sp);
                        window.draw(Button_JeuQuitterSp);
                        window.display();
                        break;
                    case MENU_WINDOW:
                        window.clear();
                        window.draw(scene.getBackground());
                        window.display();
                        break;
                    case IN_PLAY_WINDOW:
                        window.clear();
                        window.draw(scene.getBackground());
                        window.display();
                        break;
                    case TITLE_SCREEN_WINDOW:
                        window.clear();
                        window.draw(scene.getBackground());
                        window.draw(titleSprite);
                        window.draw(Button_TitleScreenSp);
                        window.display();
                        break;
                    case VIEW_CARDS_WINDOW:
                        window.clear();
                        window.draw(scene.getBackground());
                        window.draw(Right_Arrow);
                        window.draw(Left_Arrow);
                        window.draw(Card1);
                        window.draw(Card2);
                        window.draw(Card3);
                        window.draw(Button_JeuRetourSp);
                        window.display();
                    default:
                        break;
                }
            }
        }
    }
    return 0;
}
