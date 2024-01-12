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
#include <engine.h>
#include <ai.h>

using namespace std;
using namespace state;
using namespace render;

int main(int argc,char* argv[])
{

    if (argc == 1)
    {
        cout << "Welcome in our game !" << endl;
        cout << "To display Hello World : ./bin/client hello" << endl;
        cout << "To test our functions : ./bin/client test" << endl;
        cout << "To display our render : ./bin/client render" << endl;
        cout << "To play the game : ./bin/client engine" << endl;
    }
    else if (strcmp(argv[1], "hello") == 0)
    {
        cout << "Hello World from Cergy!" << endl;
    }
    else if (strcmp(argv[1], "state") == 0)
    {
        cout << "Tests" << endl;
        return boost::unit_test::unit_test_main(init_unit_test, argc, argv);
    }
    else if (strcmp(argv[1], "render") == 0)
    {
        cout << "Render" << endl;

        Static_scene scene;

        /*Création de la fenètre*/
        sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Yu-Gi-Oh!");
        sf::Vector2i windowPosition(
                sf::VideoMode::getDesktopMode().width / 2 - window.getSize().x / 2,
                sf::VideoMode::getDesktopMode().height / 2 - window.getSize().y / 2
        );
        window.setPosition(windowPosition);
        scene.init();

        cout << "Welcome in the render !" << endl;
        cout << "To display the title screen : E" << endl;
        cout << "To display the main menu : A" << endl;
        cout << "To display the game phase for player 1 : B" << endl;
        cout << "To display the game phase for player 2 : C" << endl;
        cout << "To display the deck choice for player 1 : F" << endl;
        cout << "To display the deck choice for player 2 : G" << endl;

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
                        std::cout << "Main menu" << std::endl;
                        scene.changeWindow(MAIN_WINDOW);
                    }
                    else if (event.key.code == sf::Keyboard::B) {
                        std::cout << "Game phase : J1" << std::endl;
                        scene.changeWindow(MENU_WINDOW);
                    }
                    else if (event.key.code == sf::Keyboard::C) {
                        std::cout << "Game phase: J2" << std::endl;
                        scene.changeWindow(IN_PLAY_WINDOW);
                    }
                    else if (event.key.code == sf::Keyboard::D) {
                        std::cout << "Consult Cards" << std::endl;
                        scene.changeWindow(VIEW_CARDS_WINDOW);
                    }
                    else if (event.key.code == sf::Keyboard::E){
                        std::cout << "Title Screen"  << std::endl;
                        scene.changeWindow(TITLE_SCREEN_WINDOW);
                    }
                    else if (event.key.code == sf::Keyboard::F){
                        std::cout << "Player 1 Deck Choice"  << std::endl;
                        scene.changeWindow(PLAYER_1_CHOICE);
                    }
                    else if (event.key.code == sf::Keyboard::G){
                        std::cout << "Player 2 Deck Choice"  << std::endl;
                        scene.changeWindow(PLAYER_2_CHOICE);
                    }
                }
                scene.drawSprite(scene.getWindow(),window);
            }
        }
    }

    else if (strcmp(argv[1], "engine") == 0){
        sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Yu-Gi-Oh!");
        sf::Vector2i windowPosition(
                sf::VideoMode::getDesktopMode().width / 2 - window.getSize().x / 2,
                sf::VideoMode::getDesktopMode().height / 2 - window.getSize().y / 2
        );
        window.setPosition(windowPosition);

        GameStates game;
        Static_scene scene;
        ChoiceMenu choice(&scene);
        Menu menu(&choice,&window,&scene);

        scene.init();
        menu.run();

        if(menu.getGameInit())
        {
            Boards boardplayer1;
            Boards boardplayer2;

            Decks deckPlayer1(menu.getDeckChoice1());
            Decks deckPlayer2(menu.getDeckChoice2());

            Players player1(&boardplayer1,&deckPlayer1,8000,HUMAN);
            Players player2(&boardplayer2,&deckPlayer2,8000,HUMAN);

            Dynamic_scene player1scene(&player1,&window);
            Dynamic_scene player2scene(&player2,&window);

            game.init(player1,player2);
            player1scene.init();
            player2scene.init();
            scene.initPlayerDynamicScene(&player1scene,&player2scene);

            scene.setGame(&game);
            cout << "ici" << endl;
            menu.play();
        }
    }
    return 0;
}