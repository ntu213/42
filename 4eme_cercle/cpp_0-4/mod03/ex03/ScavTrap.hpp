
#include <iostream>
#include "ClapTrap.hpp"

#ifndef SCAV_TRAP_H
# define SCAV_TRAP_H

class ScavTrap: virtual public ClapTrap
{
	protected:
		ScavTrap();
	public:
		ScavTrap(std::string nam);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
		void needEp();
		void needHp(std::string act);
};

#endif