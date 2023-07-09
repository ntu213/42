
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main()
{
	int	i = 0;
	int	n = 5;

	Zombie *horde = zombieHorde(n, "Breuuuh");
	while (i < n)
		horde[i++].announce();
	i = 0;
	delete [] horde;
	return (0);
}