
#include <iostream>
#include "Animal.hpp"

#ifndef CAT_HPP
# define CAT_HPP

class Cat: public Animal
{
	public:
		Cat();
		~Cat();
		using Animal::makeSound;
};

#endif