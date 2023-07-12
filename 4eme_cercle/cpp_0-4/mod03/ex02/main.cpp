
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap playerA("playerA");
	FragTrap playerB("playerB");

	playerA.attack(playerB.getName());
	playerB.takeDamage(playerA.getAttack());
	playerA.attack(playerB.getName());
	playerB.takeDamage(playerA.getAttack());
	playerA.beRepaired(1);
	playerB.attack(playerA.getName());
	playerA.takeDamage(playerB.getAttack());
	playerA.attack(playerB.getName());
	playerB.takeDamage(playerA.getAttack());
	playerA.highFiveGuys();
	return (0);
}