
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string nam): ClapTrap(nam)
{
	hp = 100;
	ep = 100;
	ap = 30;
	std::cout << "FragTrap " << name << " created with edit constructor\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " deleted\n";
}

void FragTrap::needEp()
{
	std::cout << "FragTrap "
		<< this->name << " don't have enough Energy\n";
}

void FragTrap::needHp(std::string act)
{
	std::cout << "FragTrap "
		<< this->name << " is dead and can't "
		<< act << "\n";
}

void FragTrap::attack(const std::string& target)
{
	if (this->hp < 1)
		return (this->needHp("attack"));
	if (!this->ep)
		return (this->needEp());
	std::cout << "FragTrap "
		<< this->name << " attacks "
		<< target << ", causing "
		<< this->ap << " points of damage!\n";
	this->ep--;
}

void FragTrap::highFiveGuys()
{
	if (this->hp < 1)
		return (this->needHp("high five"));
	if (!this->ep)
		return (this->needEp());
	std::cout << "FragTrap "
		<< this->name << " high fives!\n";
}
