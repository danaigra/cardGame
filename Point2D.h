#ifndef _DANA_POINT2D
#define _DANA_POINT2D
#include <iostream>

class Point2D
{
	int _x;
	int _y;

public:
	Point2D(int x, int y) { _x = x; _y = y; std::cout << "point2d created"; }
	~Point2D(){}
	Point2D();
    int getX(){return _x;} 
    int getY(){return _y;} 
	void setX(int x) {  _x = x; }
	void setY(int y) {  _y = y; }
};

#endif // !_DANA_POINT2D