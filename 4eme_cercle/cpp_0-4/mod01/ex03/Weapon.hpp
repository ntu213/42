
#include <iostream>

#ifndef WEAPON_H
# define WEAPON_H

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon();
		Weapon(std::string typ);
		void setType(std::string niou);
		std::string const & getType() const;
};

#endif