#include <iostream>
#include "card.h"

Card::Card(Suit suit, Rank rank) : m_Suit(suit), m_Rank(rank) { AssignValue(); }

Card::Card(int suit, int rank) : m_Suit(Suit(suit)), m_Rank(Rank(rank)) {
  AssignValue();
}

// Return formatted string of card.
string Card::ToString() {
  if (m_Flipped)
    return "UNKNOWN of UNKNOWN";

  string suit = SuitNames[(int)m_Suit];
  string rank = RankNames[(int)m_Rank];
  return rank + " of " + suit;
}

// Assign values by card rank.
// This would exist on a sub-class of "game" ideally.
void Card::AssignValue() {  
  switch (m_Rank) {
  case Rank::TWO:
    m_Value = 2;
    break;
  case Rank::THREE:
    m_Value = 3;
    break;
  case Rank::FOUR:
    m_Value = 4;
    break;
  case Rank::FIVE:
    m_Value = 5;
    break;
  case Rank::SIX:
    m_Value = 6;
    break;
  case Rank::SEVEN:
    m_Value = 7;
    break;
  case Rank::EIGHT:
    m_Value = 8;
    break;
  case Rank::NINE:
    m_Value = 9;
    break;
  case Rank::TEN:
    m_Value = 10;
    break;
  case Rank::JACK:
    m_Value = 10;
    break;
  case Rank::QUEEN:
    m_Value = 10;
    break;
  case Rank::KING:
    m_Value = 10;
    break;
  case Rank::ACE:
    m_Value = 11;
    break;
  }
}