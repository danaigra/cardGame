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
	_moves = moves;
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
    _position = destination;
}

void Player::attackUsingCard(int cardIndex)
{
    //in the future this will probably do something to the other player
}

void Player::winMatch()
{
    //in the future this will probably do something
}

void Player::loseMatch()
{
    //in the future this will probably do something
}

Point2D & Player::getPosition()
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
