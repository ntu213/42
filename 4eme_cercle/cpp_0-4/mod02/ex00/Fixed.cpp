
#include "Fixed.hpp"

Fixed::Fixed()
{
	val = 0;
	std::cout <<"Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout <<"Destructor called\n";
}

Fixed::Fixed(const Fixed & src)
{
	std::cout << "Copy constructor called\n";
	val = src.getRawBits();
}

Fixed & Fixed::operator=(const Fixed & src)
{
	std::cout << "Copy assignment operator called\n";
	this->val = src.getRawBits();
	return (*this);
}

void Fixed::setRawBits( int const raw )
{
	std::cout <<"setRawBits member function called\n";
	this->val = raw;
}

int Fixed::getRawBits( void ) const
{
	std::cout <<"getRawBits member function called\n";
	return (this->val);
}
