
#include <iostream>

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

class MateriaSource
{
	public:
		virtual ~IMateriaSource();
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
}

#endif