
#include <iostream>

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

class WrongAnimal
{
	protected:
		std::string type;
		std::string sound;
		WrongAnimal(std::string typ, std::string soond);
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal & src);
		WrongAnimal & operator=(const WrongAnimal & src);
		void makeSound() const;
		std::string getType() const;
		std::string getSound() const;
};

#endif