
#include "ClapTrap.hpp"

int main()
{
	ClapTrap playerA("playerA");
	ClapTrap playerB("playerB");

	playerA.attack(playerB.getName());
	playerB.takeDamage(playerA.getAttack());
	playerA.attack(playerB.getName());
	playerB.takeDamage(playerA.getAttack());
	playerA.beRepaired(1);
	playerB.attack(playerA.getName());
	playerA.takeDamage(playerB.getAttack());
	playerA.attack(playerB.getName());
	playerB.takeDamage(playerA.getAttack());
	return (0);
}