
#include "Character.hpp"

Character::Character()
{
	name = "Gandalf";
	inv = {NULL, NULL, NULL, NULL};
	items = 0;
	std::cout << name << " has joined the game!\n";
}

Character::Character(std::string nam)
{
	name = nam;
	inv = {NULL, NULL, NULL, NULL};
	items = 0;
	std::cout << name << " has joined the game!\n";
}

virtual Character::~Character()
{
	std::cout << name << " is corrupted! Player deleted!\n";
}

virtual std::string const & Character::getName()
{
	return (this->name);
}

virtual void Character::equip(AMateria* m)
{
	if (this->items == 4)
	{
		std::cout << "Not enough space in inventory\n";
		return ;
	}
	this->inv[this->items] = m;
	std::cout << "Item added at inventory slot " << this->items++ << '\n';
}

virtual void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid inventory slot\n";
		return ;
	}
	if (idx >= this->items)
	{
		std::cout << "This inventory slot is empty\n";
		return ;
	}
	for (int i = idx; i <= this->items; i++)
	{
		if (i != 3)
			this->inv[i] = this->inv[i + 1];
		else
			this->inv[i] = NULL;
	}
}

virtual void Character::use(int idx, Character& target)
{}
