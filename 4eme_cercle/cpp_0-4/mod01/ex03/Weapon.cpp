
#include "Weapon.hpp"

Weapon::Weapon()
{
	type = "TEKMYLOV";
}

Weapon::Weapon(std::string typ)
{
	type = typ;
}

void Weapon::setType(std::string niou)
{
	this->type = niou;
}

std::string const & Weapon::getType() const
{
	return (this->type);
}

/* Weapon & Weapon::operator=(Weapon const & other)
{

	this->type = other.getType();
}

Weapon a;
Weapon b;

a = b; */