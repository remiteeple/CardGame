#include "player.h"
#include <iostream>

using namespace std;

// Display Player's information.
void Player::Display() {
  cout << endl << "Player Hand: " << endl;
  m_pHand->Display();
  cout << "Player Total: " << m_pHand->GetTotalValue() << endl;
}