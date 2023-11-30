
#include <iostream>
#include <string>

#ifndef INFINITE_HPP
# define INFINITE_HPP

class Infinite
{
	private:
		std::string nbr;
	public:
		Infinite();
		~Infinite();
		Infinite(const Infinite & src);
		Infinite(const int & src);
		Infinite(const float & src);
		Infinite(const double & src);
		Infinite(const std::string & src);
		Infinite round(int n) const;
		const std::string & get() const;
		Infinite & operator=(const Infinite & src);
		template <typename T>
		Infinite & operator=(const T & src);

		bool operator>(const Infinite & src) const;
		bool operator<(const Infinite & src) const;
		bool operator>=(const Infinite & src) const;
		bool operator<=(const Infinite & src) const;
		bool operator==(const Infinite & src) const;
		bool operator!=(const Infinite & src) const;

		Infinite operator+(const Infinite & src) const;
		Infinite operator-(const Infinite & src) const;
		Infinite operator*(const Infinite & src) const;
		Infinite operator/(const Infinite & src) const;
		Infinite operator%(const Infinite & src) const;

		template <typename T>
		bool operator>(const T & src) const;
		template <typename T>
		bool operator<(const T & src) const;
		template <typename T>
		bool operator>=(const T & src) const;
		template <typename T>
		bool operator<=(const T & src) const;
		template <typename T>
		bool operator==(const T & src) const;
		template <typename T>
		bool operator!=(const T & src) const;

		template <typename T>
		Infinite operator+(const T & src) const;
		template <typename T>
		Infinite operator-(const T & src) const;
		template <typename T>
		Infinite operator*(const T & src) const;
		template <typename T>
		Infinite operator/(const T & src) const;

		Infinite & operator++(void); // ++prefixe
		Infinite operator++(int); // suffixe++
		Infinite & operator--(void); // --prefixe
		Infinite operator--(int); // suffixe--
};

std::ostream & operator<<( std::ostream & o, Infinite const & src );

#endif
