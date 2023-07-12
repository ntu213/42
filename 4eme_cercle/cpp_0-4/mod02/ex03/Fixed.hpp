
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

		void setRawBits( int const raw );
		int getRawBits( void ) const;
		int toInt( void ) const;
		float toFloat( void ) const;
		Fixed & operator=(const Fixed & src);

		bool operator>(const Fixed & src) const;
		bool operator<(const Fixed & src) const;
		bool operator>=(const Fixed & src) const;
		bool operator<=(const Fixed & src) const;
		bool operator==(const Fixed & src) const;
		bool operator!=(const Fixed & src) const;

		Fixed operator+(const Fixed & src) const;
		Fixed operator-(const Fixed & src) const;
		Fixed operator*(const Fixed & src) const;
		Fixed operator/(const Fixed & src) const;

		Fixed & operator++(void); // ++prefixe
		Fixed operator++(int); // suffixe++
		Fixed & operator--(void); // --prefixe
		Fixed operator--(int); // suffixe--

		static Fixed & min(Fixed & a, Fixed & b);
		static const Fixed & min(const Fixed & a, const Fixed & b);
		static Fixed & max(Fixed & a, Fixed & b);
		static const Fixed & max(const Fixed & a, const Fixed & b);
};



std::ostream & operator<<( std::ostream & o, Fixed const & src );

#endif
