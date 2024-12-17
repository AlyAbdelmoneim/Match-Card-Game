#ifndef MATCHCARD_GAME_BONUSCARD_H
#define MATCHCARD_GAME_BONUSCARD_H

#endif

#include <iostream>
#include "Card.h"
#pragma once
using namespace std;
class BonusCard : public Card {
//private:
//    int bonusValue;
public:
    BonusCard();
    BonusCard(int cardValue);
    void display() override;
//    void setBonusValue(int bonusValue);
//    int getBonusValue();
    ~BonusCard();

};