
#include <iostream>

#ifndef CLAP_TRAP_H
# define CLAP_TRAP_H

class ClapTrap
{
	protected:
		std::string name;
		int hp;
		int ep;
		int ap;
		ClapTrap();
	public:
		ClapTrap(std::string nam);
		~ClapTrap();
		ClapTrap(const ClapTrap & src);
		ClapTrap & operator=(const ClapTrap & src);
		std::string getName();
		int getAttack();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void deathMessage();
		void needEp();
		void needHp(std::string act);
};

#endif