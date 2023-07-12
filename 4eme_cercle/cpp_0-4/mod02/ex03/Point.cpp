
#include "Point.hpp"

Point::Point()
{
	x = Fixed(0);
	y = Fixed(0);
//	std::cout << "New point at coordinates: " << x << " | " << y << '\n';
}

Point::~Point()
{
//	std::cout << "Deleted point point at coordinates: " << x << " | " << y << '\n';
}

Point::Point(const float px, const float py)
{
	x = Fixed(px);
	y = Fixed(py);
//	std::cout << "New point at coordinates: " << x << " | " << y << '\n';
}

Point::Point(const Point & src)
{
	x = src.getX();
	y = src.getY();
//	std::cout << "Copied point at coordinates: " << x << " | " << y << '\n';
}

Point & Point::operator=(const Point & src)
{
	this->x = src.getX();
	this->y = src.getY();
//	std::cout << "Copied point at coordinates: " << this->x << " | " << this->y << '\n';
	return (*this);
}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}

void Point::setX(const float f)
{
	this->x = Fixed(f);
}

void Point::setY(const float f)
{
	this->y = Fixed(f);
}

void Point::setCoords(const float x, const float y)
{
	this->setX(x);
	this->setY(y);
}

void Point::printCoords() const
{
	std::cout
		<< "x: " << this->getX()
		<< "y: " << this->getY()
		<< "\n";
}
