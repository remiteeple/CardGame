#include <vector>
#include <memory>
#include "player.h"

using namespace std;

class Game {
public:
    Game();
private:
    vector<unique_ptr<Player>> m_pPlayers;
    bool m_InProgress = false;
};