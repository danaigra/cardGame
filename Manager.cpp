#include "Manager.h"

Manager::Manager(Board board)
{
	myBoard = board;
}
void Manager::getMyBoard(char* boardlen) 
{

}
Manager::~Manager() 
{

}
void Manager::start()
{

}

Player& Manager::startMatch(Match& match, ofstream& outputFile)
{
	return (match.play(outputFile));
}

void Manager::endMatch(Player& winner, Point2D point)
{
	if (&winner != NULL)
	{
		Player* looser = myBoard.getTile(point).getCurrentPlayer();
		myBoard.movePlayerTo(winner, point);
	}

}

bool Manager::startMeet(Player& p, Point2D point, ofstream& outputFile)
{
	bool result=false;
	if (this->myBoard.getTile(point).getOccupied())
	{
		Match match(p, *(myBoard.getTile(point).getCurrentPlayer()));
		endMatch(startMatch(match, outputFile), point);
	}
	else if (!(this->myBoard.getTile(point).getOccupied()) && (this->myBoard.getTile(point).getTraversable()))
	{
		myBoard.movePlayerTo(p, point);
	}
	else if (!(this->myBoard.getTile(point).getTraversable()))
	{
		
	}
	return result;
	//endMatch
}