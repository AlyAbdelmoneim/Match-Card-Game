#ifndef MATCHCARD_GAME_CARD_H
#define MATCHCARD_GAME_CARD_H
#pragma once
#endif
#include <iostream>
using namespace std;
class Card {
protected:
    string cardType;
    int cardValue;
    bool isFaceUp;
public:
    Card();
    Card(string type, int cardValue);

    string getType();
    void setType(string type);

    int getCardValue();
    void setCardValue(int cardValue);

    bool getIsFaceUp();
    void setIsFaceUp(bool isFaceUp);
// milestone 2
    void reveal();
    void hide();

    virtual void display();

    virtual ~Card();
};