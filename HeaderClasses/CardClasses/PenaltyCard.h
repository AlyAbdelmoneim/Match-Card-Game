#ifndef MATCHCARD_GAME_PENALTYCARD_H
#define MATCHCARD_GAME_PENALTYCARD_H

#endif
#pragma once
#include <iostream>
#include "Card.h"
using namespace std;
class PenaltyCard : public Card {
//private:
//    int penaltyValue;
public:
    PenaltyCard();
    PenaltyCard(int cardValue);
    void display() override;
//    void setPenaltyValue(int penaltyValue);
//    int getPenaltyValue();
    ~PenaltyCard();

};