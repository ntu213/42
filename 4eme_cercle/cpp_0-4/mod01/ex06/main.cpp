
#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl a;

	if (argc < 2)
		return (0);
	a.complain(argv[1]);
	return (0);
}