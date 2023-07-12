
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap playerA("playerA");
	ScavTrap playerB("playerB");

	playerA.attack(playerB.getName());
	playerB.takeDamage(playerA.getAttack());
	playerA.attack(playerB.getName());
	playerB.takeDamage(playerA.getAttack());
	playerA.beRepaired(1);
	playerB.attack(playerA.getName());
	playerA.takeDamage(playerB.getAttack());
	playerA.attack(playerB.getName());
	playerB.takeDamage(playerA.getAttack());
	playerA.guardGate();
	return (0);
}