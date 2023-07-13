
#include "Cat.hpp"

Cat::Cat(): Animal("Cat", "MIIIAOUUUUU")
{
	std::cout << "Uh? it's a cat? Oof...\n";
}

Cat::~Cat()
{
	std::cout << "Okay hum... It WAS a cat...\n";
}

