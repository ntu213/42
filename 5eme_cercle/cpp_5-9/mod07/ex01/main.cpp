
#include "iter.hpp"

void ft_printer(std::string & arg)
{
	std::cout << arg << std::endl;
}

int main()
{
	std::string tab[3] = {"arg 1", "arg 2", "arg 3"};
	iter(tab, 3, &ft_printer);
	return (0);
}
