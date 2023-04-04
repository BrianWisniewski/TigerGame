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
  int numCards = 0;
  int roundsPlayed = 0,
      humanWins = 0,
      computerWins = 0,
      humanTotalPoints = 0,
      computerTotalPoints = 0;
  vector<int> humanPointsByRound;
  vector<int> computerPointsByRound;
  char playAgain = 'y';

  while (playAgain == 'y') {
    // 1. Create a deck of cards and shuffle it.
    Deck deck;
    deck.shuffle();

    // 2. Create two players, each one with 5 cards in their hand.
    cout << "Welcome to TigerGame!\n"
        << "The deck was shuffled. How many cards should each player draw?\n";\
    cin >> numCards;
    while (numCards > 20 or numCards < 1) {
      cout << "Number of cards invalid! Please enter a number between 1 and 20.\n";
      cin >> numCards;
    }
    Player human(deck, numCards);
    Player computer(deck, numCards);

    // 3. Play numCards rounds. In each round:
    for (int i=0; i<numCards; i++) {
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
        cout << "Card choice invalid!\n";
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
    if (human.score > computer.score) {
      cout << "Human has won!\n";
      humanWins += 1;
    }
    else {
      cout << "Computer has won!\n";
      computerWins += 1;
    }
    computerPointsByRound.push_back(computer.score);
    computerTotalPoints += computer.score;
    humanPointsByRound.push_back(human.score);
    humanTotalPoints += human.score;
    roundsPlayed += 1;
    cout << "Would you like to play another round? (y/n): ";
    cin >> playAgain;
  }  

  cout << endl;
  for (int i=1; i <= ((int) humanPointsByRound.size()); i++) {
    cout << "Round " << i << "\n" << "Human Points: " << humanPointsByRound[i]
    << endl << "Computer Points: " << computerPointsByRound[i] << endl; 
  }
  cout << "\nHuman total score: " << humanTotalPoints << endl;
  cout << "Computer total score: " << computerTotalPoints << endl;
  cout << "Rounds Played: " << roundsPlayed << endl;
  cout << "Human Wins: " << humanWins << endl;
  cout << "Computer Wins: " << computerWins << endl;

  return 0;
}
