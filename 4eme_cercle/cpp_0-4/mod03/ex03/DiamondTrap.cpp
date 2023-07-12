
#include "DiamondTrap.hpp"

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

DiamondTrap::DiamondTrap(std::string nam): ClapTrap(nam), FragTrap(nam), ScavTrap(nam)
{
	this->name = nam;
	this->ClapTrap::name = "clap_" + nam;

	FragTrap::hp = 100;
	ScavTrap::ep = 50;
	FragTrap::ap = 30;
	std::cout << "DiamondTrap " << this->name << " created with edit constructor\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " deleted\n";
}

std::string DiamondTrap::getName()
{
	return (this->name);
}

int DiamondTrap::getAttack()
{
	return (this->ap);
}

void DiamondTrap::needEp()
{
	std::cout << "DiamondTrap "
		<< this->name << " don't have enough Energy\n";
}

void DiamondTrap::needHp(std::string act)
{
	std::cout << "DiamondTrap "
		<< this->name << " is dead and can't "
		<< act << "\n";
}

void DiamondTrap::attack(const std::string& target)
{
	if (this->hp < 1)
		return (this->needHp("attack"));
	if (!this->ep)
		return (this->needEp());
	std::cout << "DiamondTrap "
		<< this->name << " attacks "
		<< target << ", causing "
		<< this->ap << " points of damage!\n";
	this->ep--;
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->hp < 1)
		return (this->needHp("take damages"));
	std::cout << "DiamondTrap "
		<< this->name << " get attacked and take "
		<< amount << " points of damage!\n";
	this->hp -= amount;
	if (this->hp < 1)
		this->deathMessage();
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap Names: "
		<< this->name << " | "
		<< ClapTrap::getName() << '\n';
}

#endif