
#include "Fixed.hpp"

Fixed::Fixed()
{
	val = 0;
//	std::cout <<"Default constructor called\n";
}

Fixed::Fixed(const int n)
{
	val = n << litteral;
//	std::cout <<"Int constructor called\n";
}

Fixed::Fixed(const float f)
{
	val = roundf(f * (1 << litteral));
//	std::cout <<"Float constructor called\n";
}

Fixed::~Fixed()
{
//	std::cout <<"Destructor called\n";
}

Fixed::Fixed(const Fixed & src)
{
//	std::cout << "Copy constructor called\n";
	val = src.getRawBits();
}

Fixed & Fixed::operator=(const Fixed & src)
{
//	std::cout << "Copy assignment operator called\n";
	this->val = src.getRawBits();
	return (*this);
}

std::ostream & operator<<( std::ostream & o, Fixed const & src )
{
	o << src.toFloat();
	return (o);
}

void Fixed::setRawBits( int const raw )
{
	this->val = raw;
}

int Fixed::getRawBits( void ) const
{
	return (this->val);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->val) / (1 << litteral));
}

int Fixed::toInt(void) const
{
	return (this->val >> litteral);
}



bool Fixed::operator>(const Fixed & src) const
{
	return (this->val > src.getRawBits());
}

bool Fixed::operator<(const Fixed & src) const
{
	return (this->val < src.getRawBits());
}

bool Fixed::operator>=(const Fixed & src) const
{
	return (this->val >= src.getRawBits());
}

bool Fixed::operator<=(const Fixed & src) const
{
	return (this->val <= src.getRawBits());
}

bool Fixed::operator==(const Fixed & src) const
{
	return (this->val == src.getRawBits());
}

bool Fixed::operator!=(const Fixed & src) const
{
	return (this->val != src.getRawBits());
}



Fixed Fixed::operator+(const Fixed & src) const
{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed & src) const
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed & src) const
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed & src) const
{
	return (Fixed(this->toFloat() / src.toFloat()));
}


Fixed & Fixed::operator++(void)
{
	++this->val;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

Fixed & Fixed::operator--(void)
{
	--this->val;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}



Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}

const Fixed & Fixed::max(const Fixed & a, const Fixed & b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}
