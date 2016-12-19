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

void Manager::startMatch(Match& match, ofstream& outputFile)
{
	endMatch(match.play(outputFile));
}

void Manager::endMatch(Player& winner)
{
	//TODO last 3 points of match
}

void Manager::startMeet(Player& p, Point2D point)
{
	//check if the move can be done and then startMatch
	//call to endMatch
}