//*****************************************************************
//  Deck_cards.cpp
//
//  Written by George Liao on Jan 25, 2016.
//
//*****************************************************************

#include "Card.cpp"
#include <iostream>
#include <string>

class Deck_cards
{
    Card *deck;
    int number_ofcards; //track how many cards in the deck

    static const int SUITS_PER_DECK = 4;
    static const int CARDS_PER_SUIT = 13;
    static const int CARDS_PER_DECK = 52;

public:
    Deck_cards();
    void shuffle();

    //other operations besides shuffling
    void add_card(Card newcard); //add one card to the deck if it is not full
    Card get_top_card();         //deal one card
    Card peek_top_card() const;  //just peek the top card and put it back
    void cut_deck() {}           //cut the deck into two, not implemented yet

    void print_deck_cards() const;
    ~Deck_cards();
};

Deck_cards::Deck_cards()
{
    deck = new Card[CARDS_PER_DECK];
    number_ofcards = CARDS_PER_DECK;

    for (int i = 0; i < CARDS_PER_DECK; i++) {
        deck[i] = Card(Rank(i % 13), Suit(i / 13));
    }
}

void Deck_cards::shuffle()
{
    number_ofcards = CARDS_PER_DECK;
    //the deck must be full is you want to shuffle

    srand(time(NULL));
    for (int i = 0; i < CARDS_PER_DECK; i++) {
        int j = rand() % CARDS_PER_DECK;
        swap(deck[i], deck[j]);
    }
}

void Deck_cards::print_deck_cards() const
{
    for (int i = 0; i < number_ofcards; i++) {
        deck[i].print();
    }
    cout << number_ofcards << " cards left the deck" << endl << endl;
}

Deck_cards::~Deck_cards()
{
    delete[] deck;
}

void Deck_cards::add_card(Card newcard)
{
    if (number_ofcards >= CARDS_PER_DECK) {
        throw "Attempt to add a card to full deck";
    } else {
        deck[number_ofcards] = newcard;
        number_ofcards++;
    }
}

Card Deck_cards::get_top_card()
{
    //    deal the shuffled cards
    Card temporary;
    if (number_ofcards > 0) {
        temporary = deck[number_ofcards - 1];
        number_ofcards--;
    } else {
        throw "try to get a card, but there is no card left";
    }
    return temporary;
}

Card Deck_cards::peek_top_card() const
{
    //    peek the top card

    Card temporary;
    if (number_ofcards > 0) {
        temporary = deck[number_ofcards - 1];
    } else {
        throw "try to peek a card, but there is no card left";
    }
    return temporary;
}
