
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "Fat Foot";
	sound = "Graou";
	std::cout << "Another " << type << " just spawned... Oh sh*t...\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Another " << this->type << " has exploded. Splaf!\n";
}

WrongAnimal::WrongAnimal(std::string typ, std::string soond)
{
	type = typ;
	sound = soond;
	std::cout << "Another " << type << " just spawned... Oh sh*t...\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal & src)
{
	type = src.type;
	sound = src.sound;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & src)
{
	this->type = src.type;
	this->type = src.sound;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

std::string WrongAnimal::getSound() const
{
	return (this->sound);
}

void WrongAnimal::makeSound() const
{
	std::cout << this->sound << '\n';
}
