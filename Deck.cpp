#include "Deck.h"

Deck::Deck() {
    // create orange cards
    for (int i=1; i <= 10; i++) {
        Card NewCard(i, Card::orange);
        deck.push_back(NewCard);
    }
    // create purple cards
    for (int i=1; i <= 10; i++) {
        Card NewCard(i, Card::purple);
        deck.push_back(NewCard);
    }
}

void Deck::shuffle() {
    // shuffles the deck in a truly random way
    unsigned timeseed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(timeseed));
}

Card Deck::drawCard() {
    // take the first card from the deck
    Card card = deck[0];

    // remove the first card from the deck
    deck.erase(deck.begin());
    return card;
}

int Deck::getDeckSize() {
    return deck.size();
}