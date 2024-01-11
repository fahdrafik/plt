//
// Created by corte on 1/8/2024.
//
#include "ModifyHand.h"

#include <iostream>
#include <algorithm>
#include <random>

using namespace state;
using namespace std;

namespace engine {
    ModifyHand::ModifyHand() {}

    int generateRandomInt() {
        // Use a random_device to seed the random number generator
        std::random_device rd;
        // Use the random_device to generate a random seed for the generator
        std::mt19937 gen(rd());
        // Define the distribution for the range [-1, 2]
        std::uniform_int_distribution<int> distribution(-1, 2);
        return distribution(gen);
    }
    void drawCard (int attacktype, state::Players player) {
        player.drawCard();

    }
    // get the index card from render
    void placeCard (state::Players player) {

        int index = generateRandomInt();
        player.placeCard(index);

    }
}