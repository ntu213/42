
#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->tab = new T[0];
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->tab = new T[n];
	for (unsigned int i = 0; i < n; i++)
		this->tab[i] = T();
	this->_size = n;
}

template <typename T>
Array<T>::Array(Array const & src)
{
	this->tab = new T[src.size()];
	for (int i = 0; i < src.size(); i++)
		this->tab[i] = T(src[i]);
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->tab;
}

template <typename T>
Array<T> & Array<T>::operator=(Array const & src)
{
	delete[] this->tab;
	this->tab = new T[src.size()];
	for (int i = 0; i < src.size(); i++)
		this->tab[i] = T(src[i]);
}

template <typename T>
T & Array<T>::operator[](const unsigned int i) const
{
	if (i >= this->size())
		throw Array<T>::Exept();
	return (this->tab[i]);
}

template <typename T>
const T * Array<T>::getTab() const
{
	return (this->tab);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
const char* Array<T>::Exept::what() const throw()
{
	return ("Bah non en fait");
}

template <typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const & arr)
{
	try
	{
		o << "[" << arr[0];
	}
	catch (std::exception & e)
	{
		(void) e;
		o << "VOID]";
		return (o);
	}
	for (unsigned int i = 0; i < arr.size(); i++)
		o << "," << arr[i];
	o << "]";
	return (o);
}
