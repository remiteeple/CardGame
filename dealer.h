#pragma once
#include "player.h"

using namespace std;

class Dealer : public Player {
public:
  using Player::Player;

  void Game(Player);
  virtual void Display() override;
};