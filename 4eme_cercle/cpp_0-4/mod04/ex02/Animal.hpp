
#include <iostream>

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class Animal
{
	protected:
		std::string type;
		std::string sound;
		Animal(std::string typ, std::string soond);
		Animal();
		Animal(const Animal & src);
		Animal & operator=(const Animal & src);
	public:
		virtual ~Animal();
		void makeSound() const;
		std::string getType() const;
		std::string getSound() const;
};

#endif