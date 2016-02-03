//*****************************************************************
//  Deck_cards.cpp
//
//  Written by George Liao on Jan 25, 2016.
//
//*****************************************************************
#include <iostream>
#include <string>

using namespace std;

enum Suit {Diamonds, Clubs, Hearts, Spades};
enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};
//enum should be able to facilitate the cards comparison


class Card
{
    Suit suit;
    Rank rank;

public:
    Card(Rank card_rank, Suit card_suit);
    Card(){}
    void print() const;

};

Card::Card(Rank card_rank, Suit card_suit):
    suit(card_suit),
    rank(card_rank)
{
}

void Card::print() const{
    string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    string suits[] = {"Diamonds", "Clubs", "Hearts", "Spades"};
    cout << ranks[rank] + " of " + suits[suit] << std::endl;
}


