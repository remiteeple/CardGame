#include "dealer.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include <iostream>

using namespace std;

/// Ideally the core game loop would be moved to a seperate class that is then
/// ticked in a while loop by main.  This "game" class would be purely abstract
/// and implement the different rules and card valuations that various card
/// games may use.

int main() {
  // Create Deck of 52 Cards
  unique_ptr<Deck> deck = unique_ptr<Deck>(new Deck());
  deck->Populate();
  deck->Shuffle();

  // Create Player & Dealer
  unique_ptr<Player> player = make_unique<Player>();
  unique_ptr<Dealer> dealer = make_unique<Dealer>();

  // Draw Two Cards from deck.
  player->GetHand()->AddCards(move(deck->Draw(2)));
  dealer->GetHand()->AddCards(move(deck->Draw(2)));
  dealer->GetHand()->GetCard(0)->SetFlipped(true);

  // Start Blackjack.
  bool playerHit = false;
  bool gameInProgress = true;
  string input = "";
  while (gameInProgress) {
    // Display cards.
    player->Display();
    dealer->Display();

    // Game end conditions.
    if (dealer->GetHand()->GetTotalValue() >= 21 &&
        dealer->GetHand()->GetTotalValue() >= 21) { // Push
      cout << endl << "PUSH" << endl;
      gameInProgress = false;
      break;
    }

    if (player->GetHand()->GetTotalValue() >= 21) { // Player Bust
      cout << endl << "PLAYER BUST" << endl;
      gameInProgress = false;
      break;
    }

    if (dealer->GetHand()->GetTotalValue() >= 21) { // Dealer Bust
      cout << endl << "DEALER BUST" << endl;
      gameInProgress = false;
      break;
    }

    // Receive input.
    cout << endl << "'hit' or 'stay'?" << endl;
    cin >> input;

    if (input == "hit") {
      player->GetHand()->AddCards(move(deck->Draw(1)));
      playerHit = true;
    } else if (input == "stay") {
      playerHit = false;
    }

    // Pseudeo Dealer AI
    if (!playerHit) {
      if (dealer->GetHand()->GetTotalValue() <= 10) { // Dealer Hit
        if (dealer->GetHand()->HasFlipped()) {
          dealer->GetHand()->RevealFlipped();
          continue;
        } else {
          dealer->GetHand()->AddCards(move(deck->Draw(1)));
        }
      } else if (dealer->GetHand()->GetTotalValue() <= 11 &&
                 dealer->GetHand()->GetTotalValue() < 15) {
        if (dealer->GetHand()->HasFlipped()) {
          dealer->GetHand()->RevealFlipped();
          continue;
        }

        if (1 + rand() % 2) {
          dealer->GetHand()->AddCards(move(deck->Draw(1)));
        }
      } else if (dealer->GetHand()->GetTotalValue() >= 15) { // Dealer Stay
        continue;
      }
    }
  }
  return 0;
}