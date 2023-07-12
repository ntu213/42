
#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#ifndef DIAMOND_TRAP_H
# define DIAMOND_TRAP_H

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string name;
		DiamondTrap();
	public:
		DiamondTrap(std::string nam);
		~DiamondTrap();
		std::string getName();
		void needEp();
		void needHp(std::string act);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		int getAttack();
		void whoAmI();
};

#endif