
#include <iostream>
#include "AMateria.hpp"

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

class MateriaSource
{
	private:
		int copied;
		AMateria* mats[4];
	public:
		MateriaSource();
		~MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif