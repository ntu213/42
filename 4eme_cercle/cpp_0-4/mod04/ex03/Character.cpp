
#include "Character.hpp"

Character::Character()
{
	name = "Gandalf";
	for (int i = 0; i < 4; i++)
		inv[i] = NULL;
	items = 0;
	std::cout << name << " has joined the game!\n";
}

Character::Character(std::string nam)
{
	name = nam;
	for (int i = 0; i < 4; i++)
		inv[i] = NULL;
	items = 0;
	std::cout << name << " has joined the game!\n";
}

Character::~Character()
{
	std::cout << name << " is corrupted! Deleting related files...\n";
	for (int i = 0; i < 4; i++)
		if (this->inv[i])
			delete this->inv[i];
	std::cout << "Player deleted!\n";
}

std::string const & Character::getName()
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (this->items == 4)
	{
		std::cout << "Not enough space in inventory\n";
		return ;
	}
	int i = 0;
	while (this->inv[i])
		i++;
	this->inv[i] = m;
	std::cout << "Item added at inventory slot " << i << '\n';
	this->items++;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid inventory slot\n";
		return ;
	}
	if (!this->inv[idx])
	{
		std::cout << "This inventory slot is empty\n";
		return ;
	}
	this->inv[idx] = NULL;
	this->items--;
}

void Character::use(int idx, Character& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid inventory slot\n";
		return ;
	}
	if (!this->inv[idx])
	{
		std::cout << "This inventory slot is empty\n";
		return ;
	}
	this->inv[idx]->use(target);
	delete this->inv[idx];
	this->inv[idx] = NULL;
	this->items--;
}
