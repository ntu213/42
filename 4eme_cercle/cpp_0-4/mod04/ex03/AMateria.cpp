
#include "AMateria.hpp"

AMateria(std::string const & typ)
{
	type = typ;
	std::cout << "New item of type \"" << type << "\" created\n";
}

~AMateria()
{
	std::cout << "Item \"" << this->type << "\" destoyed\n";
}

AMateria(const AMateria & src)
{
	type = src.type;
	std::cout << "Item \"" << type << "\" Cloned\n";
}

AMateria & operator=(const AMateria & src)
{
	this->type = src.type;
	std::cout << "Item \"" << type << "\" Cloned by operator\n";
}

std::string const & getType() const
{
	return (this->type);
}

virtual AMateria* clone() const = 0
{
	AMateria *res = new AMateria(*this);
	return (res);
}

virtual void use(ICharacter& target)
{}
