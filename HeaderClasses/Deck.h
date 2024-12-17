#ifndef MATCHCARD_GAME_DECK_H
#define MATCHCARD_GAME_DECK_H

#endif
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "CardClasses/Card.h"
#include "CardClasses/StandardCard.h"
#include "CardClasses/BonusCard.h"
#include "CardClasses/PenaltyCard.h"
#pragma once

using namespace std;

class Deck {
private:
    Card** cards;
    int numofcards;
public:
    Deck();
    ~Deck();
    void  shuffle();
    void displayGrid();
    Card** getCards();
    void setCards(Card** cards);
    int& getnumofcards();
    void decreasenumofcards();
    void initializeDeck();
//milestone 2
    Card& revealCard(int x, int y);

    void hideCard(int x, int y);

    void removeCard(int x, int y);
};