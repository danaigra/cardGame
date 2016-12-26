#include "Square.h"
using namespace std;

void Square::setIsOccupied(bool toset) {
	isOccupied = toset;
}

Square::Square(bool isoccopied, Player * player, bool travel, Point2D point)
{
	isOccupied = isoccopied;
	currentPlayer = player;
	isTraversable = travel;
	point = point;
}

void Square::addPlayer(Player * currnetPlayer)
{
	currentPlayer = currnetPlayer;
	isOccupied = true;
}

void Square::removePlayer(Player * currentplayer)
{
	isOccupied = false;
	currentPlayer = NULL;
}

bool Square::getOccupied()
{
	return isOccupied;
}

bool Square::getTraversable()
{
	return isTraversable;
}

Player* Square::getCurrentPlayer()
{
	return currentPlayer;
}

