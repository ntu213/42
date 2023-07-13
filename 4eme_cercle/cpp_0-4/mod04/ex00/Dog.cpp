
#include "Dog.hpp"

Dog::Dog(): Animal("Dog", "OUAFFE")
{
	std::cout << "Okay, it's not the worse thing...\n";
}

Dog::~Dog()
{
	std::cout << "Uh... I think the microwave was a bad idea...\n";
}
