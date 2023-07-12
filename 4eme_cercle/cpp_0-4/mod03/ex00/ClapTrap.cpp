
#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
{
	name = "Discord Admin";
	hp = 10;
	ep = 10;
	ap = 1;
	std::cout << "ClapTrap " << name << " created with default constructor\n";
}

ClapTrap::ClapTrap(std::string nam)
{
	name = nam;
	hp = 10;
	ep = 10;
	ap = 0;
	std::cout << "ClapTrap " << name << " created with edit constructor\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " deleted\n";
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	name = src.name;
	hp = src.hp;
	ep = src.ep;
	ap = src.ap;
	std::cout << "ClapTrap " << name << " created by copy\n";
}

ClapTrap & ClapTrap::operator=(const ClapTrap & src)
{
	this->name = src.name;
	this->hp = src.hp;
	this->ep = src.ep;
	this->ap = src.ap;
	std::cout << "ClapTrap " << name << " called copy assignement\n";
	return (*this);
}

std::string ClapTrap::getName()
{
	return (this->name);
}

int ClapTrap::getAttack()
{
	return (this->ap);
}

void ClapTrap::deathMessage()
{
	std::cout << "ClapTrap "
		<< this->name << " is dead\n";
}

void ClapTrap::needEp()
{
	std::cout << "ClapTrap "
		<< this->name << " don't have enough Energy\n";
}

void ClapTrap::needHp(std::string act)
{
	std::cout << "ClapTrap "
		<< this->name << " is dead and can't "
		<< act << "\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hp < 1)
		return (this->needHp("attack"));
	if (!this->ep)
		return (this->needEp());
	std::cout << "ClapTrap "
		<< this->name << " attacks "
		<< target << ", causing "
		<< this->ap << " points of damage!\n";
	this->ep--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp < 1)
		return (this->needHp("take damages"));
	std::cout << "ClapTrap "
		<< this->name << " get attacked and take "
		<< amount << " points of damage!\n";
	this->hp -= amount;
	if (this->hp < 1)
		this->deathMessage();
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hp < 1)
		return (this->needHp("be repaired"));
	if (!this->ep)
		return (this->needEp());
	std::cout << "ClapTrap "
		<< this->name << " has been repaired and got "
		<< amount << " Hit point!\n";
	this->hp += amount;
	this->ep--;
}
