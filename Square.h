#pragma once

#include "Player.h"

class Square {
	private:
		bool isOccupied;
		Player* currentPlayer;
		bool isTraversable;
		Point2D point;

	public:
		void setIsOccupied(bool toset);
		Square(bool, Player*, bool, Point2D);
		void addPlayer(Player* currnetPlayer);
		void removePlayer(Player* currentplayer);
		bool getOccupied();
		bool getTraversable();
		Player* getCurrentPlayer();
};