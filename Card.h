#ifndef _DANA_CARD
#define _DANA_CARD

#include <iostream>
const int NAME_LEN = 30;
enum Color {
	red,
	green,
	blue,
	purple,
	orange
};

inline Color string_to_color(char color[])
{
	if (!strcmp(color, "Red"))
		return red;
	else if (!strcmp(color, "Green"))
		return green;
	else if (!strcmp(color, "Blue"))
		return blue;
	else if (!strcmp(color, "Purple"))
		return purple;
	else 
        return orange;
}

class Card {
	char* _name;
	int _num;
	Color _color;

public:
	void printCard();
	Card(char* name, int num, Color color);
	~Card();
	Card();
};
#endif // !_DANA_CARD
