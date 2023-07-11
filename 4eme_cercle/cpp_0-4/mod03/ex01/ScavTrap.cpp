
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	name = "Stylish Discord Admin";
	hp = 100;
	ep = 50;
	ap = 20;
}

ScavTrap::ScavTrap(std::string nam)
{
	name = nam;
	hp = 100;
	ep = 50;
	ap = 20;
}

ScavTrap::~ScavTrap() {}

ScavTrap::ScavTrap(const ScavTrap & src)
{
	name = src.name;
	hp = src.hp;
	ep = src.ep;
	ap = src.ap;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & src)
{
	this->name = src.name;
	this->hp = src.hp;
	this->ep = src.ep;
	this->ap = src.ap;
	return (*this);
}

std::string ScavTrap::getName()
{
	return (this->name);
}

int ScavTrap::getAttack()
{
	return (this->ap);
}

void ScavTrap::deathMessage()
{
	std::cout << "ScavTrap "
		<< this->name << " is dead\n";
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

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->hp < 1)
		return (this->needHp("take damages"));
	std::cout << "ScavTrap "
		<< this->name << " get attacked and take "
		<< amount << " points of damage!\n";
	this->hp -= amount;
	if (this->hp < 1)
		this->deathMessage();
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hp < 1)
		return (this->needHp("be repaired"));
	if (!this->ep)
		return (this->needEp());
	std::cout << "ScavTrap "
		<< this->name << " has been repaired and got "
		<< amount << " Hit point!\n";
	this->hp += amount;
	this->ep--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap "
		<< this->name << " turned into Gate Keeper mode\n";
}
