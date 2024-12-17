#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "HeaderClasses/CardClasses/Card.h"
#include "HeaderClasses/CardClasses/StandardCard.h"
#include "HeaderClasses/CardClasses/BonusCard.h"
#include "HeaderClasses/CardClasses/PenaltyCard.h"
#include "HeaderClasses/Player.h"
#include "HeaderClasses/Deck.h"
#include "HeaderClasses/Game.h"
using namespace std;
Card::Card() {
    this->cardType = "Standard";
    this->cardValue = 0;
    this->isFaceUp = false;
}
Card::Card(string cardType, int cardValue) {
    this->cardType = cardType;
    this->cardValue = cardValue;
    this->isFaceUp = false;
}

string Card::getType(){
    return this->cardType;
}
void Card::setType(string type){
    this->cardType = type;
}

int Card::getCardValue(){
    return this->cardValue;
}
void Card::setCardValue(int cardValue){
    this->cardValue = cardValue;
}

bool Card::getIsFaceUp(){
    return this->isFaceUp;
}

void Card::setIsFaceUp(bool isFaceUp){
    this->isFaceUp = isFaceUp;
}
//milestone 2
void Card::reveal() {
    this->isFaceUp=true;
}
void Card::hide() {
    this->isFaceUp=false;
}

void Card::display() {
    if(this->isFaceUp){
        cout << this->cardType[0] << ":" <<this->cardValue << " ";
    } else {
        cout << "*" << " ";
    }
}

Card::~Card() {}


StandardCard::StandardCard() : Card("Standard", 0) {}

StandardCard::StandardCard(int cardValue)
        :Card("Standard", cardValue) {}

void StandardCard::display() {
    if(this->isFaceUp){
        cout <<"S:"<<this->cardValue << " ";
    } else {
        cout << "*" << " ";
    }
}

StandardCard::~StandardCard() {}

BonusCard::BonusCard():Card("Bonus", 7){}

BonusCard::BonusCard(int cardValue):Card("Bonus", cardValue){}

void BonusCard::display() {
    if(this->isFaceUp){
        cout <<"B:"<<this->cardValue << " ";
    } else {
        cout << "*" << " ";
    }
}

BonusCard::~BonusCard() {}




PenaltyCard::PenaltyCard():Card("PenaltyCard", 8) {}

PenaltyCard::PenaltyCard(int cardValue):Card("PenaltyCard", cardValue) {}


void PenaltyCard::display() {
    if(this->isFaceUp){
        cout <<"P:"<<this->cardValue << endl;
    } else {
        cout << "*" << " ";
    }
}

PenaltyCard::~PenaltyCard() {}


Deck::Deck() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator
    this->initializeDeck();
    numofcards=16;
}

void Deck::shuffle() {
    Card** temp = new Card*[4];
    for (int i = 0; i < 4; ++i) {
        temp[i] = new Card[4];
    }
    vector<vector<bool> > isTaken(4, vector<bool>(4, false));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int index1 = rand() % 4;
            int index2 = rand() % 4;
            while(isTaken[index1][index2]){
                index1 = rand() % 4;
                index2 = rand() % 4;
            }
            isTaken[index1][index2] = true;
            temp[i][j] = this->cards[index1][index2];
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            this->cards[i][j] = temp[i][j];
        }
    }
    delete[] temp;
}

void Deck::displayGrid() {
    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->cards[i][j].display();
        }
        cout << endl;
    }
}
Card** Deck::getCards() {
    return this->cards;
}
void Deck::setCards(Card** cards) {
    this->cards = cards;
}
int Deck::getnumofcards() {
    return numofcards;
}
void Deck::decreasenumofcards() {
    getnumofcards()-1;
}



//milestone 2
void Deck::initializeDeck() {
    numofcards=16;
    this->cards = new Card*[4];
    for (int i = 0; i < 4; ++i) {
        cards[i] = new Card[4];
    }
    int value = 1;
    int SCards = 0;
    int BCards = 0;
    int PCards = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int cardType = rand() % 3;
            if (cardType == 0 && SCards < 12) {
                this->cards[i][j] = StandardCard(value);
                SCards++;
                value++;
                if (value > 6) value = 1;
            }
            else if (cardType == 1 && BCards < 2) {
                this->cards[i][j] = BonusCard(7);
                BCards++;
            }
            else if (cardType == 2 && PCards < 2) {
                this->cards[i][j] = PenaltyCard(8);
                PCards++;
            }
            else {
                if (SCards < 12) {
                    this->cards[i][j] = StandardCard(value);
                    value++;
                    SCards++;
                    if (value > 6) value = 1;
                }
                else if (BCards < 2) {
                    this->cards[i][j] = BonusCard(7);
                    BCards++;
                }
                else if (PCards < 2) {
                    this->cards[i][j] = PenaltyCard(8);
                    PCards++;
                }
            }
        }
    }
}
Card& Deck::revealCard(int x ,int y ) {
    return this-> cards[x][y];
}

void Deck::hideCard(int x,int y) {
    this->cards[x][y].hide();
}
void Deck::removeCard(int x,int y ) {
    this->cards[x][y].setIsFaceUp(true);
    numofcards--;
}



Deck::~Deck() {
    for (int i = 0; i < 4; ++i) {
        delete[] this->cards[i];
    }
    delete[] this->cards;
}


Player::Player() {
    this->name = "";
    this->score = 0;
}

Player::Player(string name, int score) {
    this->name = name;
    this->score = score;
}

Player::~Player() {}


void Player::setName(string name) {
    this->name = name;
}

string Player::getName() {
    return this->name;
}

void Player::setScore(int score) {
    this->score = score;
}

int Player::getScore() {
    return this->score;
}

//milestone 2
void Player::increaseScore(int points) {
    this->score += points;
}

void Player::decreaseScore(int points) {
    this->score -= points;
}
void Player::displayScore() {
    printf("Player %s has a score of %d\n", this->name.c_str(), this->score);
}


Game::Game() {
    this->player1 = Player();
    this->player2 = Player();
    this->deck = new Deck();
}

Game::Game(Player player1, Player player2, Deck* deck) {
    this->player1 = player1;
    this->player2 = player2;
    this->deck = deck;
    currentPlayerIndex=0;
    skipNextTurn=false;
    playagain=false;
}

Game::~Game() {
    delete this->deck;
}

void Game::initializeGame() {
    cout << "Enter Player 1 Name: ";
    string name;
    cin >> name;
    this->player1.setName(name);
    cout << "Enter Player 2 Name: ";
    cin >> name;
    this->player2.setName(name);

    this->deck->initializeDeck();
    this->deck->shuffle();
    this->deck->displayGrid();

    currentPlayerIndex = 0;

    while (!gameEnd()) {
        Player& currentPlayer = (currentPlayerIndex == 0) ? player1 : player2;
        PlayerTurn(currentPlayer);
        switchTurn();
    }
}

//milestone 2
void Game::PlayerTurn(Player currentPlayer) {

    int x1, y1, x2, y2;
    cout << currentPlayer.getName() << "'s turn!" << endl;

    while (true) {
        cout << "choose first card (x y): ";
        cin >> x1 >> y1;
        cout << "choose second card (x y): ";
        cin >> x2 >> y2;
        if(x1<0 || x1>3 || y1<0 || y1 >3 || x2<0 || x2>3 || y2<0 || y2 >3 ){
            cout<<"wrong input"<<endl;
        }
        if (x1 == x2 && y1 == y2) {
            cout << "you can't select the same card twice" << endl;
            continue;
        }
        if (this->deck->revealCard(x1, y1).getIsFaceUp() || this->deck->revealCard(x2, y2).getIsFaceUp()) {
            cout << "the first card that has been selected was already chosen, please choose a different card" << endl;
            continue;
        }
        break;
    }


    Card& card1 = this->deck->revealCard(x1, y1);
    Card& card2 = this->deck->revealCard(x2, y2);


    if (card1.getCardValue() == 7 && card2.getCardValue() == 7) {
        cout << "two Bonus Cards revealed" << endl;
        int choice;
        cout << "enter 1 to gain +2 points, or 2 to gain +1 point and take another turn: ";
        cin >> choice;

        if (choice == 1) {
            currentPlayer.increaseScore(2);
        } else if (choice == 2) {
            currentPlayer.increaseScore(1);
            playagain = true;
            return;
        }

        this->deck->removeCard(x1, y1);
        this->deck->removeCard(x2, y2);



    } else if (card1.getCardValue() == 8 && card2.getCardValue() == 8) {
        cout << "two Penalty Cards revealed" << endl;
        int choice;
        cout << "enter 1 to lose 2 points, or 2 to lose 1 point and skip the next turn: ";
        cin >> choice;

        if (choice == 1) {
            currentPlayer.decreaseScore(2);
        } else if (choice == 2) {
            currentPlayer.decreaseScore(1);
            skipNextTurn = true;
        }

        this->deck->removeCard(x1, y1);
        this->deck->removeCard(x2, y2);
        //   this->deck->setnumofcards(2);
    } else if ((card1.getCardValue() == 7 && card2.getCardValue() == 8) || (card1.getCardValue() == 8 && card2.getCardValue() == 7)) {
        cout << "bonus and penalty cards have been revealed , no effect on score" << endl;
        this->deck->removeCard(x1, y1);
        this->deck->removeCard(x2, y2);
        //   this->deck->setnumofcards(2);
    } else if (card1.getCardValue() == 7 || card2.getCardValue() == 7) {
        currentPlayer.increaseScore(1);
        card1.reveal();
        card2.reveal();
        this->deck->displayGrid();
        cout << "one bonus card revealed, score increased by 1 " << endl;
        cin.get();
        cin.get();
        this->deck->removeCard((card1.getCardValue() == 7) ? x1 : x2, (card1.getCardValue() == 7) ? y1 : y2);
        //this->deck->setnumofcards(1);
        this->deck->hideCard((card1.getCardValue() != 7) ? x1 : x2, (card1.getCardValue() != 7) ? y1 : y2);

    } else if (card1.getCardValue() == 8 || card2.getCardValue() == 8) {

        currentPlayer.decreaseScore(1);
        card1.reveal();
        card2.reveal();
        this->deck->displayGrid();
        cout << "one penalty card revealed, score decreased by 1 " << endl;
        cin.get();
        cin.get();
        this->deck->removeCard((card1.getCardValue() == 8) ? x1 : x2, (card1.getCardValue() == 8) ? y1 : y2);
        // this->deck->setnumofcards(1);
        this->deck->hideCard((card1.getCardValue() != 8) ? x1 : x2, (card1.getCardValue() != 8) ? y1 : y2);

    } else if (card1.getCardValue() == card2.getCardValue()) {
        cout << "match " << currentPlayer.getName() << " gains 1 point" << endl;
        currentPlayer.increaseScore(1);
        this->deck->removeCard(x1, y1);
        this->deck->removeCard(x2, y2);
        // this->deck->setnumofcards(2);
    } else {

        card1.reveal();
        card2.reveal();
        this->deck->displayGrid();
        cout<<"press enter to continue"<<endl;
        cin.get();
        cin.get();
        card1.hide();
        card2.hide();
        cout << "no match, next player’s turn." << endl;
    }

    this->deck->displayGrid();
}

bool Game::gameEnd() {
    if (this->deck->getnumofcards() <= 1) {
        cout << "game over " << endl;
        cout<<player1.getName()<<"'s score:"<<player1.getScore()<<endl;
        cout<<player2.getName()<<"'s score:"<<player2.getScore()<<endl;
        if (player1.getScore() > player2.getScore()) {
            cout << player1.getName() << " wins" << endl;
        } else if (player2.getScore() > player1.getScore()) {
            cout << player2.getName() << " wins" << endl;
        } else {
            cout << "it's a tie" << endl;
        }
        return true;
    }


    bool allMatched = true;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!this->deck->revealCard(i, j).getIsFaceUp()) {
                allMatched = false;
                break;
            }
        }
    }
    if (allMatched) {
        cout << "all cards are matched" << endl;
        if (player1.getScore() > player2.getScore()) {
            cout << player1.getName() << " wins" << endl;
        } else if (player2.getScore() > player1.getScore()) {
            cout << player2.getName() << " wins" << endl;
        } else {
            cout << "it's a tie" << endl;
        }
        return true;
    }

    return false;
}



void Game::switchTurn() {

    if(playagain) {
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
        playagain=false;
     }
    if (skipNextTurn) {
        PlayerTurn(currentPlayerIndex ? player1 : player2);
        cout << "Turn is skipped " << endl;
        skipNextTurn = false;
    }
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
}