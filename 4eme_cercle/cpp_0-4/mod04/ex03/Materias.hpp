
#include "AMateria.hpp"

#ifndef ICE_HPP
# define ICE_HPP

class Ice: public AMateria
{
	public:
		Ice();
		void use(Character& target);
};

#endif

#ifndef CURE_HPP
# define CURE_HPP

class Cure: public AMateria
{
	public:
		Cure();
		void use(Character& target);
};

#endif