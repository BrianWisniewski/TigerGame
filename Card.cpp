#include "Card.h"

Card::Card(int rank, Color color) {
    // had to use scope resolution because the var names conflict
    Card::rank = rank;
    Card::color = color;
    // if card is purple value is rank
    // if card is orange, value is rank times two
    if (color == purple)
        value = rank;
    else
        value = rank*2;
}

// returns the formatted output string of the card
std::string Card::printCard() {
    std::stringstream ss;
    std::string colorString;
    // map enum values to strings
    if (color == 0)
        colorString = "purple";
    else
        colorString = "orange";
    ss << colorString << ":" << rank;
    return ss.str();
}

int Card::getRank() {
    return rank;
}

Card::Color Card::getColor() {
    return color;
}

int Card::getValue() {
    return value;
}