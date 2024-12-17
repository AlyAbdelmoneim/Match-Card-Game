#ifndef MATCHCARD_GAME_STANDARDCARD_H
#define MATCHCARD_GAME_STANDARDCARD_H

#endif

#include <iostream>
#include "Card.h"
#pragma once
using namespace std;
class StandardCard : public Card {
public:
    StandardCard();
    StandardCard(int cardValue);
    void display() override;
    ~StandardCard();
};