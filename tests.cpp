//*****************************************************************
//  tests.cpp
//
//  Written by George Liao on Jan 25, 2016.
//
//*****************************************************************

#include "Deck_cards.cpp"


int main(int argc, char **argv){

    try {
        Deck_cards newdeck;
        newdeck.shuffle();
        newdeck.print_deck_cards();
        Card topone = newdeck.peek_top_card();
        topone.print();
        Card toptwo = newdeck.get_top_card();
        toptwo.print();
        newdeck.print_deck_cards();
    } catch (const char* msg) {
        cerr << msg << endl;
    }

}
