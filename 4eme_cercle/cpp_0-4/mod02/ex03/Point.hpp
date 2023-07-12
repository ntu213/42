
#include <iostream>
#include "Fixed.hpp"

#ifndef POINT_HPP
# define POINT_HPP

class Point
{
	private:
		Fixed x;
		Fixed y;
	public:
		Point();
		~Point();
		Point(const float px, const float py);
		Point(const Point & src);
		Point & operator=(const Point & src);
		Fixed getX() const;
		Fixed getY() const;
		void setX(const float f);
		void setY(const float f);
		void setCoords(const float x, const float y);
		void printCoords() const;
};

#endif