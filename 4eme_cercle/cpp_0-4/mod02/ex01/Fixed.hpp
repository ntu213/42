
#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int	val;
		static const int	litteral = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed & src);
		Fixed & operator=(const Fixed & src);
		void setRawBits( int const raw );
		int getRawBits( void ) const;
		int toInt( void ) const;
		float toFloat( void ) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & src );

#endif
