
#include "Point.hpp"


static Fixed abs(Fixed x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

static Fixed area(Point const t1, Point const t2, Point const t3)
{
	return (((Fixed(-1) * t2.getY()) * t3.getX() +
			t1.getY() * ((Fixed(-1) * t2.getX()) +
			t3.getX()) + t1.getX() * (t2.getY() -
			t3.getY()) + t2.getX() * t3.getY()) /
			Fixed(2));
}

bool bsp( Point const t1, Point const t2, Point const t3, Point const p)
{
/*
	std::cout << "DEBUG: \n";
	t1.printCoords();
	t2.printCoords();
	t3.printCoords();
	p.printCoords();
*/

	Fixed res = abs(area(t1, t2, t3));
	Fixed a = abs(area(p, t2, t3));
	Fixed b = abs(area(p, t1, t3));
	Fixed c = abs(area(p, t2, t1));

	return (res == a + b + c);
}