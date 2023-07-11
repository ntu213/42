
#include <iostream>

#ifndef SCAV_TRAP_H
# define SCAV_TRAP_H

class ScavTrap
{
	private:
		std::string name;
		int hp;
		int ep;
		int ap;
		ScavTrap();
	public:
		ScavTrap(std::string nam);
		~ScavTrap();
		ScavTrap(const ScavTrap & src);
		ScavTrap & operator=(const ScavTrap & src);
		std::string getName();
		int getAttack();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void guardGate();
		void deathMessage();
		void needEp();
		void needHp(std::string act);
};

#endif