
#include <iostream>

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter (T* tab, int n, void (*ft)(T &))
{
	for (int i = 0; i < n; i++)
		ft(tab[i]);
}

#endif
