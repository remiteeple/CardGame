#include "player.h"
#include <iostream>

using namespace std;

// Display Pla
void Player::Display() {
  cout << endl << "Player Hand: " << endl;
  m_pHand->Print();
  cout << "Player Total: " << m_pHand->GetTotalValue() << endl;
}