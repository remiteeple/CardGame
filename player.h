#pragma once
#include "hand.h"

using namespace std;

class Player {
public:
  Player() { m_pHand = make_unique<Hand>(); }
  virtual ~Player() {}

  void SetScore(int score) { m_Score = score; }
  int GetScore() const { return m_Score; }
  unique_ptr<Hand> &GetHand() { return m_pHand; }
  virtual void Display();

protected:
  unique_ptr<Hand> m_pHand;
  int m_Score = 0;
};