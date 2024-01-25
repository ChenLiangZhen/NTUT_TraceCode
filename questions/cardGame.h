//
// Created by Light Chen on 2024/1/25.
//

#ifndef TRACECODE_CARDGAME_H
#define TRACECODE_CARDGAME_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

class Card {
private:
    int value;
    string suit;
public:
    Card(int value, string suit) {
        this->value = value;
        this->suit = suit;
    }

    int getScore() {
        map<string, int> suitCode = {{"spade",   4},
                                     {"heart",   3},
                                     {"diamond", 2},
                                     {"club",    1}};
        int score = value * 10 + suitCode[suit];
        return score;
    }
};

class Player {
private:
    vector<Card *> cards;
public:
    Player() {}

    int getRank() {
        int rank = 0;
        for (int i = 0; i < cards.size(); i++) {
            rank += cards[i]->getScore();
        }
        return rank;
    }

    void addCard(Card *card) {
        cards.push_back(card);
    }
};

class PokerGame {

private:
    unique_ptr<Player> human, computer;

    void init() {
        human = make_unique<Player>();
        computer = make_unique<Player>();
    };

public:
    PokerGame() {}

    void deal(vector<Card *> inCards) {
        init();
        for (int i = 0; i < inCards.size(); i += 2) {
            human->addCard(inCards[i]);
            computer->addCard(inCards[i + 1]);
        }
    }

    string play() {
        stringstream ss1, ss2;
        string s1, s2 ,result;
        ss1 << human->getRank();
        ss1 >> s1;
        ss2 << computer->getRank();
        ss2 >> s2;
        result = "Player=" + s1 + ", Computer=" + s2;
        if (human->getRank() > computer->getRank()) {
            result += ", Player Win!\n";
        } else if (human->getRank() < computer->getRank()) {
            result += ", Computer Win!\n";
        } else {
            result += ", Push.\n";
        }
        return result;
    }
};

void execute_card_game(){

    PokerGame game;
    vector<Card *> inCards1 = {new Card(5, "spade"), new Card(6, "spade")};
    vector<Card *> inCards2 = {new Card(6, "spade"), new Card(5, "spade"),
                               new Card(5, "heart"), new Card(6, "heart")};
    vector<Card *> inCards3 = {new Card(9, "spade"), new Card(9, "club"),
                                 new Card(8, "diamond"), new Card(8, "heart")};
    game.deal(inCards1);
    cout << game.play();
    game.deal(inCards2);
    cout << game.play();
    game.deal(inCards3);
    cout << game.play();

    for (auto card : inCards1) delete card;
    for (auto card : inCards2) delete card;
    for (auto card : inCards3) delete card;
}

#endif //TRACECODE_CARDGAME_H
