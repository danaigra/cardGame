#ifndef _DANA_MANAGER
#define _DANA_MANAGER

#include <iostream>
#include <fstream>
#include "Board.h"


class Manager {
private:
	Board myBoard;
	vector <Player> activePlayers;
	vector <Player> nonActivePlayers;

	ifstream _simulationFile;
	vector<Player*> _playersVec;
	ofstream _outputFile;

public:
	Manager();
	void start();
	void stop();
	void startMeet();
	void endMeet();
	void startMatch();
	void endMatch();

};


#endif // !_DANA_MANAGER
