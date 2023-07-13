
#include "Dog.hpp"

Dog::Dog(): Animal("Dog", "OUAFFE")
{
	std::cout << "Okay, it's not the worse thing...\n";
	brain = new Brain();
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Uh... I think the microwave was a bad idea...\n";
}
