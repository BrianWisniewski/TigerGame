#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main() {
  // initialize all variables
  Card cpuCard;
  Card humanCard;
  int cpuChoice = 0;
  int humanChoice = 0;

  // 1. Create a deck of cards and shuffle it.
  Deck deck;
  deck.shuffle();

  // 2. Create two players, each one with 5 cards in their hand.
  Player human(deck, 5);
  Player computer(deck, 5);

  cout << "Welcome to TigerGame!\n"
       << "The deck was shuffled and each player has drawn 5 cards.\n\n";

  // 3. Play five rounds. In each round:
  for (int i=0; i<5; i++) {
    // Print the round number
    cout << "Round " << i+1 << "\n-------";

    // Have computer deal a card from their hand.
    srand(time(0));
    cpuChoice = rand() % computer.hand.getHandSize() + 1;
    cpuCard = computer.hand.dealCard(cpuChoice);
    cout << "\nThe computer plays: " << cpuCard.printCard();

    // Show human their hand of cards so that they can make a selection.
    cout << "\nYour hand: " << human.hand.printHand();
    cout << "\nWhich card do you want to play? ";
    cin >> humanChoice;

    // Have human deal their card. 
    // ensure the choice is valid
    // if it is not, reprompt the user
    while (humanChoice > human.hand.getHandSize() or humanChoice < 1) {
      cout << "Card choice invalid!";
      cout << "Which card do you want to play? ";
      cin >> humanChoice;
    }
    humanCard = human.hand.dealCard(humanChoice);
    cout << "You played: " << humanCard.printCard() << endl;
    
    // Determine who won the round and update points accordingly.
    // Human Wins
    if (humanCard.getValue() > cpuCard.getValue()) {
      human.score += humanCard.getValue() + cpuCard.getValue();
      cout << "You win this round!\n";
    }
    // Computer wins
    else if (humanCard.getValue() < cpuCard.getValue()) {
      computer.score += humanCard.getValue() + cpuCard.getValue();
      cout << "The computer wins this round!\n";
    }
    // Tie
    else {
      cout << "Tie!\n";
    }


    // Print results for current round.
    cout << "\nCurrent Scores:\n"
      << "Human: " << human.score << endl
      << "Computer: " << computer.score << "\n\n";  
  }

  // 4. Print final game results.  
  cout << "FINAL SCORE:\n"
       << "Human: " << human.score << endl
       << "Computer: " << computer.score << "\n\n";  
  if (human.score > computer.score)
    cout << "Human has won!\n";
  else
    cout << "Computer has won!\n";
  
  
  return 0;
}
