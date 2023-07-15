
#include "AMateria.hpp"

AMateria::AMateria(const std::string & typ)
{
	type = typ;
	std::cout << "New item of type \"" << type << "\" created\n";
}

AMateria::~AMateria()
{
	std::cout << "Item \"" << this->type << "\" destroyed\n";
}

AMateria::AMateria(const AMateria & src)
{
	type = src.type;
	std::cout << "Item \"" << type << "\" cloned\n";
}

AMateria & AMateria::operator=(const AMateria & src)
{
	this->type = src.type;
	std::cout << "Item \"" << type << "\" cloned by operator\n";
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

AMateria* AMateria::clone() const
{
	return (new AMateria(*this));
}

void AMateria::use(Character& target)
{
	(void) target;
}
