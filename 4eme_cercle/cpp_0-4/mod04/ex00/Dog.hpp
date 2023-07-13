
#include <iostream>
#include "Animal.hpp"

#ifndef DOG_HPP
# define DOG_HPP

class Dog: public Animal
{
	public:
		Dog();
		~Dog();
		using Animal::makeSound;
};

#endif