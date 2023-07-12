
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const t1, Point const t2, Point const t3, Point const point);

int main( void )
{
	Point a;
	Point b(9.9, 15.1);
	Point c(7.3, 8.2);
	a.setCoords(18.2, 13.3);

	Point p1(11.15, 12.3);
	Point p2(14.3, 9.1);

	if (bsp(a, b, c, p1))
		std::cout << "p1 est dans le triangle\n";
	else
		std::cout << "p1 n'est pas dans le triangle\n";

	if (bsp(a, b, c, p2))
		std::cout << "p2 est dans le triangle\n";
	else
		std::cout << "p2 n'est pas dans le triangle\n";

	return 0;
}

