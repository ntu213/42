
#include <iostream>

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	private:
		T *tab;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const & src);
		~Array();
		Array<T> & operator=(Array const & src);
		T & operator[](const unsigned int i) const;
		unsigned int size() const;
		const T * getTab() const;
		class Exept: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

template <typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const & arr);

#include "Array.tpp"

#endif
