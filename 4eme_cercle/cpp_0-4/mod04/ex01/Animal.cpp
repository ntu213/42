
#include "Animal.hpp"

Animal::Animal()
{
	type = "lguerrer";
	sound = "lililuulelilillelele";
	std::cout << "Another " << type << " just spawned... Oh sh*t...\n";
}

Animal::~Animal()
{
	std::cout << "Another " << this->type << " has exploded. Splaf!\n";
}

Animal::Animal(std::string typ, std::string soond)
{
	type = typ;
	sound = soond;
	std::cout << "Another " << type << " just spawned... Oh sh*t...\n";
}

Animal::Animal(const Animal & src)
{
	type = src.type;
	sound = src.sound;
}

Animal & Animal::operator=(const Animal & src)
{
	this->type = src.type;
	this->type = src.sound;
	return (*this);
}

std::string Animal::getType() const
{
	return (this->type);
}

std::string Animal::getSound() const
{
	return (this->sound);
}

void Animal::makeSound() const
{
	std::cout << this->sound << '\n';
}
