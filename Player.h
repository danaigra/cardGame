#ifndef _DANA_PLAYER
#define _DANA_PLAYER

#include <iostream>
#include <vector>
#include "Card.h"
#include "Point2D.h"

class Player {
    static const int MAX_CARDS;
    std::vector<Card*> _cardsVec;
	char* _name;
	int _ID;
	int _wins;
	int _loss;
	int _moves;
	Point2D _position;
public:
	Player(std::vector<Card*>, char* name, int ID, int wins, int loss, int moves, Point2D position);
	Player();
	Player(char* name, int ID, int wins, int loss, Point2D position);
    ~Player();
    void setCards(std::vector<Card*> cards);
    void addCard(Card* pCard);
    void printPlayer();
    void moveToPoint(Point2D destination); 
    int getID(){return _ID;}
    void attackUsingCard(int cardIndex);
    void winMatch();
    void loseMatch();
	Point2D & getPosition();

};

#endif // !_DANA_PLAYER