#pragma once
#include "card.h"
#include <memory>
#include <vector>

using namespace std;

class Hand {
public:
  void Display();
  void AddCards(vector<unique_ptr<Card>> cards);
  unique_ptr<Card> &GetCard(int index) { return m_pCards[index]; }
  int GetSize() { return m_pCards.size(); }
  int GetTotalValue();
  bool HasFlipped();
  void RevealFlipped();

  unique_ptr<Card> &operator[](int index);

private:
  vector<unique_ptr<Card>> m_pCards;
};