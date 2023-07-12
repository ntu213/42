
#include <iostream>
#include "ClapTrap.hpp"

#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

class FragTrap: public ClapTrap
{
	private:
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