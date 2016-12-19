#include "Board.h"

Square& Board::getTile(Point2D & location) const {
	return *gameBoard.at(location.getX()).at(location.getY());
}


int Board::movePlayerTo(Player& p, Point2D & location) {
	
	int toRerturn = 0;
	if (location.getX() > 0 && location.getY() > 0 && location.getX()<this->gameBoard.size() && location.getY()<this->gameBoard[0].size())
	{
		Point2D oldPosition = p.getPosition();
		p.moveToPoint(location);
		Square* t = this->gameBoard[location.getX()].at(location.getY());
		t->setIsOccupied(true);
		Square* t2 = this->gameBoard[oldPosition.getX()].at(oldPosition.getY());
		t2->setIsOccupied(false);
		toRerturn = 1;
	}
	

	return toRerturn;
}

void Board::addBoard(vector <vector<Square*>> & gameboard)
{
	this->gameBoard = gameboard;
}