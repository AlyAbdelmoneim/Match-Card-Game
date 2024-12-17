#ifndef MATCHCARD_GAME_GAME_H
#define MATCHCARD_GAME_GAME_H

#endif
#include <iostream>
#include <vector>
#include "CardClasses/Card.h"
#include "Deck.h"
#include "Player.h"
#pragma once

using namespace std;

class Game {
private:
    //checked--
    bool skipNextTurn;
    Player player1;
    Player player2;
    Deck* deck;
    int currentPlayerIndex;
public:
    Game();
    Game(Player player1, Player player2, Deck* deck);
    ~Game();
    void initializeGame();

    void PlayerTurn(Player currentPlayer);

    bool gameEnd();

    void switchTurn();
};