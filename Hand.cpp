#include "Hand.h"

Hand::Hand(Deck deck, int N) {
    for (int i=0; i < N; i++) {
        // draw N number of cards from the deck
        hand.push_back(deck.drawCard());
    }
}

std::string Hand::printHand() {
    std::stringstream ss;
    for (int i=0; i < (int)hand.size(); i++) {
        Card currentCard = hand[i];
        // holds the string value of the Color enum
        std::string colorString;
        
        // convert the color enum to the string equivalent
        if (currentCard.getColor() == Card::purple)
            colorString = "purple";
        else
            colorString = "orange";
    
        // create the string for one card value
        ss << "[" << i+1 << "] " << colorString << ":" << currentCard.getRank()
           << " ";
    }
    // after all cards have been added into the stream, return the string-stream
    return ss.str();
}

Card Hand::dealCard(int num) {
    // save the numth element so it can be returned later
    Card dealedCard = hand[num-1];
    // remove the numth element from the vector
    hand.erase(hand.begin()+num-1);
    return dealedCard;
}

int Hand::getHandSize() {
    return hand.size();
}
