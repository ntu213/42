
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef CAT_HPP
# define CAT_HPP

class Cat: public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		~Cat();
		using Animal::makeSound;
};

#endif