#include <iostream>
 // Assurez-vous d'inclure les fichiers d'en-tête appropriés
#include "main.h"

int main() {
    // Créez des joueurs
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
}
