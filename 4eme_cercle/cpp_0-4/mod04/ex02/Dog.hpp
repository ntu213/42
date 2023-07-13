
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef DOG_HPP
# define DOG_HPP

class Dog: public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		~Dog();
		using Animal::makeSound;
};

#endif