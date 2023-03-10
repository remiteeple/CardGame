#pragma once
#include "card.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector> // <stack> could be used as an alternative

using namespace std;

class Deck {
public:
  void Shuffle();
  void Populate();
  vector<unique_ptr<Card>> Draw(int count);

private:
  vector<unique_ptr<Card>> m_pCards;
};