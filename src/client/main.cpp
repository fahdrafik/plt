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
        scene.setTitleScene();
        /*Menu du jeu*/
        scene.setMenuScene();
        /*En cours de jeu : vue du premier joueur*/
        scene.setInGameScene();
        /*En cours de jeu : vue du deuxième joueur*/
        /*Menu Pause du jeu */
        /*Menu : Consultation des cartes*/

        scene.setConsultScene();
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

                scene.drawSprite(scene.getWindow(),window);
            }
        }
    }
    return 0;
}
