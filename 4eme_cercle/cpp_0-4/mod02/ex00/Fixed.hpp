
#include <iostream>

class Fixed
{
	private:
		int	val;
		static const int	litteral = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed & src);
		Fixed & operator=(const Fixed & src);
		void setRawBits( int const raw );
		int getRawBits( void ) const;
};
