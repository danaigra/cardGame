#include "Player.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

const int Player::MAX_CARDS = 5;

Player::Player(std::vector<Card*> cards, char * name, int ID, int wins, int loss, int moves, Point2D position)
{
	for (int i = 0; i < MAX_CARDS && i < cards.size() ; i++)
	{
		_cardsVec[i] = cards[i];
	}

	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
	_ID = ID;
	_wins = wins;
	_loss = loss;
	_moves = moves = 3;
	_position = position;
	cout << "player created" << endl;
}

Player::~Player()
{
    if( _name != NULL)
    {
	    delete[] _name;
    }
	for (int i = 0; i < _cardsVec.size() ; i++)
	{
		delete _cardsVec[i];
	}

	cout << "player destroyed" << endl;
}

Player::Player(char* name, int ID, int wins, int loss, Point2D position)
{
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
	_ID = ID;
	_wins = wins;
	_loss = loss;
	_position = position;
	cout << "player created" << endl;
}

Player::Player()
{
    _name = NULL;
	cout << "player created" << endl;
}

void Player::setCards(std::vector<Card*> cards)
{
    _cardsVec.clear();
	for(int i = 0; i < MAX_CARDS && i < cards.size() ; i++)
	{
		_cardsVec[i] = cards[i];
	}
}

void Player::addCard(Card* pCard)
{
    if(_cardsVec.size() < MAX_CARDS)
    {
        _cardsVec.push_back(pCard);
    }
}

void Player::printPlayer()
{
    cout << "Player data: name - " << _name << ", ID - " << _ID 
         << ", wins - " << _wins << ", losses - " << _loss << ", position - " << _position.getX() << ":" << _position.getY() << endl;
    cout << "has these cards: "  << endl;
	for(int i = 0; i < _cardsVec.size() ; i++)
	{
		_cardsVec[i]->printCard();
	}
}

void Player::moveToPoint(Point2D destination)
{
	if (getMoves() > 0)
	{
		_moves--;
		_position = destination;
	}
	else
	{
		cout << "Move is deined , plase chak youer Moves point " << endl;
	}
}

void Player::attackUsingCard(int cardIndex)
{
	//_cardsVec.at(cardIndex)->;
}

void Player::winMatch()
{
	_wins++;
}

void Player::loseMatch()
{
	_loss++;
}

Point2D& Player::getPosition()
{
	return _position;
}

int Player::getNumOfCards()
{
	return _cardsVec.size();
}

Card * Player::getRandCard()
{
	int iSecret, iGuess;
	srand(time(NULL));
	iSecret = rand() % _cardsVec.size();
	_usesCards.push_back(_cardsVec[iSecret]);
	_cardsVec.erase(_cardsVec.begin() + iSecret);
	return _usesCards.back();
}
void Player::restPlayer() 
{
	_moves = 3;
}

void Player::removeUsedCars(int i)
{
	for (int j = 0; j < i; j++)
	{
		Card* c = _usesCards.back();
		_cardsVec.push_back(c);
		_usesCards.pop_back();
	}
}