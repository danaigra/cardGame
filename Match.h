#pragma once

#include "Player.h"

class Match {
private:
	Player player1;
	Player player2;

public:
	Match(Player& p1, Player& p2);
	Player& play();
};
