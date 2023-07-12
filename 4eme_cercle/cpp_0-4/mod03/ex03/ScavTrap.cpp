
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string nam): ClapTrap(nam)
{
	hp = 100;
	ep = 50;
	ap = 20;
	std::cout << "ScavTrap " << name << " created with edit constructor\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " deleted\n";
}

void ScavTrap::needEp()
{
	std::cout << "ScavTrap "
		<< this->name << " don't have enough Energy\n";
}

void ScavTrap::needHp(std::string act)
{
	std::cout << "ScavTrap "
		<< this->name << " is dead and can't "
		<< act << "\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hp < 1)
		return (this->needHp("attack"));
	if (!this->ep)
		return (this->needEp());
	std::cout << "ScavTrap "
		<< this->name << " attacks "
		<< target << ", causing "
		<< this->ap << " points of damage!\n";
	this->ep--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap "
		<< this->name << " turned into Gate Keeper mode\n";
}
