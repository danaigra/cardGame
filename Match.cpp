#include "Match.h"


Match::Match(Player & p1, Player & p2)
{
	player1 = p1;
	player2 = p2;
}


int getScoreByColor(Card* c1, Card* c2)
{
	if (c1->getColor() == blue && c2->getColor() == red)
	{
		return c1->getNum() * 2;
	}
	else if (c1->getColor() == red && c2->getColor() == green)
	{
		return c1->getNum() * 2;
	}
	else if (c1->getColor() == green && c2->getColor() == blue)
	{
		return c1->getNum() * 2;
	}
	else if (c1->getColor() == purple && c2->getColor() == orange)
	{
		return c1->getNum() * 1.5;
	}
	return c1->getNum();
}


Player & Match::play(ofstream& outputFile)
{
	int i = 0;
	int scoreP1 = 0;
	int scoreP2 = 0;
	Player* p = NULL;
	for ( i = 0; i < 3; i++)
	{
		Card* c1=player1.getRandCard();
		Card* c2 = player2.getRandCard();
		if (c1->getNum() > c2->getNum())
		{
			scoreP1+= getScoreByColor(c1, c2);
			if (c2->getColor() != purple)
				scoreP2 += getScoreByColor(c2, c1);
		}
		else if (c1->getNum() < c2->getNum())
		{
			scoreP2 += getScoreByColor(c2, c1);
			if (c1->getColor() != purple)
				scoreP1 += getScoreByColor(c1, c2);
		}
		else 
		{
			scoreP1 += getScoreByColor(c1, c2);
			if (c2->getColor() != purple)
				scoreP2 += getScoreByColor(c2, c1);
			else
				scoreP2 += c2->getNum();
		}
		outputFile << "#" << player1.getID() << " ATK " << c1->getNum() << endl;
		outputFile << "#" << player2.getID() << " ATK " << c2->getNum() << endl;
	}
	if (scoreP1 > scoreP2)
		
		return player1;
	else if (scoreP2 > scoreP1)
		return player2;
	else
	{
		player1.removeUsedCars(i);
		player2.removeUsedCars(i);
		return *p;
	}
}
