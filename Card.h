#ifndef CARD_H_
#define CARD_H_

#include <string>
#include <sstream>

class Card
{
public:
    enum Color {purple, orange};

private:
    int rank = 0,
        value = 0;
    Color color = purple;

public:
    Card() = default;
    Card(int rank, Color color);
    std::string printCard();
    int getRank();
    Color getColor();
    int getValue();
};

#endif // CARD_H_
