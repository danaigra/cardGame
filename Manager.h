#ifndef _DANA_MANAGER
#define _DANA_MANAGER

#include <iostream>
#include <fstream>
#include "Board.h"
#include "Match.h"


class Manager {
private:
	Board myBoard;
	vector <Player> activePlayers;
	vector <Player> nonActivePlayers;

	ifstream _simulationFile;
	vector<Player*> _playersVec;
	ofstream _outputFile;

public:
	Manager(Board board);
	~Manager();
	void start();
	void stop();
	bool startMeet(Player& p, Point2D point, ofstream& outputFile);
	void endMeet();
	Player& startMatch(Match& match, ofstream& outputFile);
	void endMatch(Player& winner, Point2D point);
	void getMyBoard(char* boardlen);

};


#endif // !_DANA_MANAGER
