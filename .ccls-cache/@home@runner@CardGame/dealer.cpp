#include "dealer.h"
#include <iostream>

using namespace std;

// Display dealer's information.
void Dealer::Display() {
  cout << endl << "Dealer Hand: " << endl;
  m_pHand->Print();
  cout << "Dealer Total: " << m_pHand->GetTotalValue() << endl;
}