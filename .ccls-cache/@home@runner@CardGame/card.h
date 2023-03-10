#pragma once
#include <string>

using namespace std;

class Card {
public:
  // Card Suit Definitions
  enum class Suit { HEARTS, CLUBS, SPADES, DIAMONDS };
  const char *SuitNames[4] = {"HEARTS", "CLUBS", "SPADES", "DIAMONDS"};

  // Card Rank Definitions
  enum class Rank {
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
  };
  const char *RankNames[13] = {"TWO",   "THREE", "FOUR", "FIVE", "SIX",
                               "SEVEN", "EIGHT", "NINE", "TEN",  "JACK",
                               "QUEEN", "KING",  "ACE"};

  Card(Suit suit, Rank rank);
  Card(int suit, int rank);

  void AssignValue();
  // ideally this function would live on a sub-class of the "game" class to
  // implement different card values per game!

  int GetValue() const { return m_Value; }
  Rank GetRank() const { return m_Rank; }
  Suit GetSuit() const { return m_Suit; }
  string ToString();
  void SetFlipped(bool flipped) { m_Flipped = flipped; }
  bool GetFlipped() { return m_Flipped; }

private:
  int m_Value = 0;
  Rank m_Rank;
  Suit m_Suit;
  bool m_Flipped = false;
};