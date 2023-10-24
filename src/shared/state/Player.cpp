#include "Player.h"

// Constructeur de la classe Player
Player::Player(const std::string& playerName) : name(playerName) {
    // Initialisez d'autres membres si nécessaire
}

// Méthode pour le joueur de piocher une carte
void Player::drawCard() {
    // Implémentez la logique pour piocher une carte depuis le deck
}

// Méthode pour le joueur de jouer une carte depuis sa main
void Player::playCard(const Card& card) {
    // Implémentez la logique pour jouer une carte depuis la main
}

// Méthode pour activer l'effet d'une carte
void Player::activateEffect(const Card& card) {
    // Implémentez la logique pour activer l'effet d'une carte
}

// Méthode pour placer un monstre sur le terrain
void Player::setMonster(const Monster& monster) {
    // Implémentez la logique pour placer un monstre sur le terrain
}

// Méthode pour placer un sort sur le terrain
void Player::setSpell(const Spell& spell) {
    // Implémentez la logique pour placer un sort sur le terrain
}

// Méthode pour terminer le tour du joueur
void Player::endTurn() {
    // Implémentez la logique pour terminer le tour du joueur
}

// Méthode pour attaquer l'adversaire avec un monstre
void Player::attackOpponent(Player& opponent, const Monster& attackingMonster) {
    // Implémentez la logique pour gérer l'attaque d'un monstre contre l'adversaire
    // Calculez les dommages, vérifiez les conditions de victoire, etc.
}
