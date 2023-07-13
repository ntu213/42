
#include <iostream>
#include "WrongAnimal.hpp"

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		using WrongAnimal::makeSound;
};

#endif