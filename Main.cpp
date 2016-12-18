//dana igra 311117899
//daniel yosef 203550215

#include <iostream>
#include "Card.h"
#include "Player.h"
#include "Point2D.h"
#include <fstream>
#include <vector>
#include "Manager.h"
#include "Square.h"
#include "Board.h"
#include <string.h>

using namespace std;

void main(int argc, char ** argv)
{
	vector<Player*> playersVec;

	char typeofobject;
	char skipline[1000];
	char name[30];
	char scardVal[3];
	char scolor[7];
	char sID[4];
	char swins[3];
	char slosses[3];
	char sposx[4];
	char sposy[4];
	string tempBuff;
	int num;
	Manager mymanger;
	if (argc < 3)
	{
		cout << "not enough parameters" << endl;
		exit(0);
	}

	ifstream creationFile(argv[1]);
	ifstream simulationFile(argv[2]);
	ofstream outputFile("./output.txt");
	if (!creationFile.good() || !simulationFile.good() || !outputFile.good())
	{
		cout << "there was a problem opening the files" << endl;
		exit(0);
	}

	while (!creationFile.eof())
	{
		typeofobject = creationFile.get();
		if (typeofobject == 'B')
		{
			int i = 0;
			creationFile.getline(skipline, 1000, '\n');//skip ','
			while (creationFile.get()!='B')
			{
			creationFile.getline(tempBuff ,'\n');
			}
			
		}
		if (typeofobject == 'C')
		{
			creationFile.get();//skip the ','
			creationFile.get();//skip the ' '
			creationFile.get();//skip the '"'
			creationFile.getline(name, 29, '"');
			creationFile.get();//skip the ','
			creationFile.getline(scardVal, 3, ',');
			creationFile.getline(scolor, 7, '\n');
			int cardval = atoi(scardVal);
			Color color = string_to_color(scolor);
			if (playersVec.size() > 0)
			{
				playersVec[playersVec.size() - 1]->addCard(new Card(name, cardval, color));
			}
		}
		else if (typeofobject == 'P')
		{
			creationFile.get();//skip the ','
			creationFile.getline(sID, 4, ',');
			creationFile.getline(name, 29, ',');
			creationFile.getline(swins, 3, ',');
			creationFile.getline(slosses, 3, ',');
			creationFile.getline(sposx, 4, ':');
			creationFile.getline(sposy, 4, '\n');
			int playerID = atoi(sID);
			int playerwins = atoi(swins);
			int playerlosses = atoi(slosses);
			int playerposx = atoi(sposx);
			int playerposy = atoi(sposy);
			Point2D point(playerposx, playerposy);
			playersVec.push_back(new Player(name, playerID, playerwins, playerlosses, point));
		}
		else if (typeofobject == '#')
		{
			creationFile.getline(skipline, 1000, '\n');
		}
	}

	//read the simulation and do the actions

	while (!simulationFile.eof())
	{
		char strPlayerID[10];
		char strCommand[20];
		int playerID;
		char firstLetter = simulationFile.get();
		if (firstLetter >= '0' && firstLetter <= '9')
		{
			strPlayerID[0] = firstLetter;
			simulationFile >> &strPlayerID[1];
			playerID = atoi(strPlayerID);
			simulationFile >> strCommand;

			if (strcmp(strCommand, "MOVE") == 0)
			{
				int posx;
				int posy;
				simulationFile >> posx;
				simulationFile.get(); //skip the ':'
				simulationFile >> posy;
				simulationFile.get(); //skip the '\n'
				for (int i = 0; i < playersVec.size(); i++)
				{
					if (playersVec[i]->getID() == playerID)
					{
						playersVec[i]->moveToPoint(Point2D(posx, posy));
						cout << "Moving player #" << playerID << " to " << posx << ":" << posy << endl;
						outputFile << "Moving player #" << playerID << " to " << posx << ":" << posy << endl;
						break;
					}
				}
			}
			else if (strcmp(strCommand, "PRINT") == 0)
			{
				for (int i = 0; i < playersVec.size(); i++)
				{
					if (playersVec[i]->getID() == playerID)
					{
						cout << "Printing details of player #" << playerID << endl;
						outputFile << "Printing details of player #" << playerID << endl;
						playersVec[i]->printPlayer();

						break;
					}
				}
			}
			else if (strcmp(strCommand, "ATK") == 0)
			{
				Player* attacker = NULL;
				Player* defender = NULL;
				int defenderID;
				int attackCardIndex;
				simulationFile >> defenderID;
				simulationFile >> attackCardIndex;

				for (int i = 0; i < playersVec.size(); i++)
				{
					if (playersVec[i]->getID() == playerID)
					{
						attacker = playersVec[i];
					}
					if (playersVec[i]->getID() == defenderID)
					{
						defender = playersVec[i];
					}
				}

				if (attacker != NULL && defender != NULL)
				{
					cout << "Player #" << playerID << " attacks player #" << defenderID << " using card #" << attackCardIndex << endl;
					outputFile << "Player #" << playerID << " attacks player #" << defenderID << " using card #" << attackCardIndex << endl;
					attacker->attackUsingCard(attackCardIndex);
				}
			}
		}
		else if (typeofobject == '#') //skip comment line
		{
			creationFile.getline(skipline, 1000, '\n');
		}
	}
	mymanger()
}

