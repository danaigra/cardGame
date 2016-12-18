#pragma once

#include "Square.h"
#include <vector>
#include "Point2D.h"

using namespace std;

class Board {
private:
	vector <vector<Square*>> gameBoard;

public:
	Square & getTile(Point2D & location) const;
	int movePlayerTo(Player& p, Point2D & location);
};
