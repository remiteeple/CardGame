#include "hand.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Display all cards in hand.
void Hand::Display() {
  for (unique_ptr<Card> &card : m_pCards)
    cout << card->ToString() << endl;
}

unique_ptr<Card> &Hand::operator[](int index) { return m_pCards[index]; }

// Add card(s) to hand.
void Hand::AddCards(vector<unique_ptr<Card>> cards) {
  for (auto &card : cards)
    m_pCards.push_back(move(card));
  cards.clear();
}

// Get the sum of all cards in hand's value.
int Hand::GetTotalValue() {
  int sum = 0;
  for (auto &card : m_pCards) {
    Card::Rank rank = card->GetRank();
    int value = card->GetValue();

    if (card->GetFlipped()) // ignore flipped cards
      continue;

    // if (rank == Card::Rank::ACE && (sum + value) > 21) // Aces condition
    //   continue;
    sum += value;
  }
  return sum;
}

// Return whether the hand has a flipped card.
bool Hand::HasFlipped() {
  for (auto &card : m_pCards)
    if (card->GetFlipped()) return true;
  return false;
}

// Reveal all flipped cards.
void Hand::RevealFlipped() {
  for (auto &card : m_pCards)
    if (card->GetFlipped()) card->SetFlipped(false);
}