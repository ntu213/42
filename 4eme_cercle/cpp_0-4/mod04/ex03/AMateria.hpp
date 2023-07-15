
#include <iostream>

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include "Character.hpp"

class AMateria
{
	private:
		AMateria();
	protected:
		std::string type;
	public:
		AMateria(const std::string & typ);
		virtual ~AMateria();
		AMateria(const AMateria & src);
		AMateria & operator=(const AMateria & src);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const;
		virtual void use(Character& target);
};

#endif