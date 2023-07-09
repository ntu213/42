
#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "Franky";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " just exploded bloodly! Splash!\n";
}

std::string Zombie::getName()
{
	return (this->name);
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name)
{
	this->name = name;
}