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

        sf::RenderWindow window(sf::VideoMode(1000, 800), "Yu-Gi-Oh!");

        /*Première page du jeu*/
        /*Titre*/
        sf::Sprite titleSprite;
        sf::Texture titleTexture;
        titleTexture.loadFromFile("./Images/yugioh.png");
        titleSprite.setTexture(titleTexture);

        //sf::Vector2u windowSize = window.getSize();
        //sf::Vector2u titleTextureSize = titleTexture.getSize();
        //titleSprite.setPosition((windowSize.x - titleTextureSize.x) / 1.0f, (windowSize.y - titleTextureSize.y) / 1.0f);
        titleSprite.setScale(0.4f,0.4f);
        titleSprite.setPosition(300,400);

        /*Boutons pour le menu principal et l'écran titre*/
        sf::RectangleShape Button_TitleScreen(sf::Vector2f(200, 100));
        Button_TitleScreen.setPosition(400,550);

        /*Menu du jeu*/

        /*En cours de jeu : vue du premier joueur*/

        /*En cours de jeu : vue du deuxième joueur*/

        /*Menu : Consultation des cartes*/

        while (window.isOpen())
        {
            // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
            sf::Event event;

            window.clear();
            window.draw(scene.getBackground());
            window.draw(titleSprite);
            window.display();

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
                        }
                        else if (event.key.code == sf::Keyboard::B) {
                            std::cout << "Phase de jeu : J1" << std::endl;
                        }
                        else if (event.key.code == sf::Keyboard::C) {
                            std::cout << "Phase de jeu : J2" << std::endl;
                        }
                        else if (event.key.code == sf::Keyboard::D) {
                            std::cout << "Consultation des cartes" << std::endl;
                        }
                }
            }
        }
    }
    return 0;
}
