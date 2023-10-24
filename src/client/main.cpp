#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include <state.h>

using namespace std;
using namespace state;

int main(int argc,char* argv[])
{
    Exemple exemple;
    exemple.setX(53);

    cout << "It works !" << endl;

    return 0;
}
/*
 *     // Créez des joueurs
    Player player1("Joueur 1");
    Player player2("Joueur 2");

    // Créez un état de jeu initial avec les joueurs
    State gameState({player1, player2});

    // Démarrez le jeu
    gameState.startGame();

    // Exécutez un certain nombre de tours ou un scénario de jeu ici
    // gameState.playTurn();
    // ...

    // Terminez le jeu
    gameState.endGame();

    // Affichez le score ou l'état final du jeu
    gameState.displayScore();

    return 0;
 */