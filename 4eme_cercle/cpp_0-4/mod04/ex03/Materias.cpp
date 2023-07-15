
#include "Materias.hpp"

Ice::Ice(): AMateria("ice") {}

void Ice::use(Character& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Cure::Cure(): AMateria("cure") {}

void Cure::use(Character& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

