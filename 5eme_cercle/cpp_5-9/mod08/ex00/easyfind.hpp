
#include <iostream>

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template <typename T>
int easyfind(T const & t, int n)
{
	int ret = 0;
	typename T::const_iterator it;
	for (it = t.begin(); it != t.end() && t.at(ret) != n; it++, ret++){}
	return (it == t.end() ? throw std::out_of_range("Out of range") : ret);
}

#endif
