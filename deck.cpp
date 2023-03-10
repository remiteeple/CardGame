#include "deck.h"
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

// Generate a deck of 52 cards.
void Deck::Populate() {
  for (int i = 0; i < 13; ++i) {
    for (int j = 0; j < 4; ++j) {
      m_pCards.push_back(make_unique<Card>(j, i));
    }
  }
}

// Shuffle deck randomly.
void Deck::Shuffle() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle(m_pCards.begin(), m_pCards.end(), std::default_random_engine(seed));
}

// Draw from top of deck.
vector<unique_ptr<Card>> Deck::Draw(int count) {
  vector<unique_ptr<Card>> draw;
  count = m_pCards.size() - count;
  for (int i = 0; i <= count; i++) {
    // Performant as per https://stackoverflow.com/a/48683251
    draw.insert(draw.end(), make_move_iterator(m_pCards.begin() + count),
                make_move_iterator(m_pCards.end()));
    m_pCards.erase(m_pCards.begin() + count, m_pCards.end());
  }
  return draw;
}