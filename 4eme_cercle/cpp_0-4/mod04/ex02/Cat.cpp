
#include "Cat.hpp"

Cat::Cat(): Animal("Cat", "MIIIAOUUUUU")
{
	std::cout << "Uh? it's a cat? Oof...\n";
	brain = new Brain();
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Okay hum... It WAS a cat...\n";
}

