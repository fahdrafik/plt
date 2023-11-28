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

        sf::RenderWindow window(sf::VideoMode(1200, 800), "Yu-Gi-Oh!");

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

        /*En cours de jeu : vue du deuxième joueur*/

        /*Menu Pause du jeu */

        /*Menu : Consultation des cartes*/

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
                        window.display();
                    default:
                        break;
                }
            }
        }
    }
    return 0;
}
