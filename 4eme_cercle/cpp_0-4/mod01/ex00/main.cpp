
#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	Zombie	*gerard;

	gerard = newZombie("Gerard");
	gerard->announce();
	randomChump("Bertrand");

	delete gerard;
	return (0);
}