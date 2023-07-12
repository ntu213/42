
#include <iostream>
#include "ClapTrap.hpp"

#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

class FragTrap: virtual public ClapTrap
{
	protected:
		FragTrap();
	public:
		FragTrap(std::string nam);
		~FragTrap();
		void attack(const std::string& target);
		void highFiveGuys();
		void needEp();
		void needHp(std::string act);
};

#endif