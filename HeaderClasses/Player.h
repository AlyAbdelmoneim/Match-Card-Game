#ifndef MATCHCARD_GAME_PLAYER_H
#define MATCHCARD_GAME_PLAYER_H

#endif
#include <iostream>
#include <vector>
#include "CardClasses/Card.h"
#include "Deck.h"
#pragma once

using namespace std;

class Player {
private:
    string name;
    int score;
public:
    Player();
    Player(string name,int score) ;
    ~Player();
    void displayScore();
    void setName(string name);
    string getName();
    void setScore(int score);
    int getScore();
//milestone 2
    void increaseScore(int points);

    void decreaseScore(int points);

};