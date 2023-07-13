
#include <iostream>
#include "Character.hpp"

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class AMateria
{
	private:
		AMateria();
	protected:
		std::string typ;
	public:
		AMateria(std::string const & typ);
		~AMateria();
		AMateria(const AMateria & src);
		AMateria & operator=(const AMateria & src);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const;
		virtual void use(Character& target);
};

#endif