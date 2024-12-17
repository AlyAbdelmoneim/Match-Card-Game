#include <iostream>
#include "HeaderClasses/Game.h"  // Include your header file for Game class

using namespace std;

int main() {
    // Create a new Game object
    Game CardGame;

    // Initialize the game with player names and shuffle the deck
    CardGame.initializeGame();

    return 0;
}
