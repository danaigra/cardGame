#pragma once

#include "Player.h"

class Square {
	private:
		bool isOccupied;
		Player* currentPlayer;
		bool isTraversable;

	public:
		void setIsOccupied(bool toset);
};