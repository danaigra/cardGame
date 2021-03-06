#include "Card.h"
using namespace std;

void Card::printCard()
{
    cout << "Card data: name - " << _name << ", num - " << _num << ", color - " << _color << endl;
}

Card::Card(char * name, int num, Color color)
{
	_name = new char[strlen(name) + 1];
	strcpy(_name ,name);
	_num = num;
	_color = color;
	use = 0;
	cout << "card created" << endl;
}

Card::~Card()
{
    if( _name != NULL)
    {
	    delete[] _name;
    }
	cout << "card destroyed" << endl;
}

Card::Card()
{
    _name = NULL;
	cout << "card created" << endl;
}

int Card::getNum()
{
	return _num;
}

Color Card::getColor()
{
	return _color;
}
void Card::setUse() 
{
	use = 1;
}
bool Card::getUse()
{
	return use;
}
