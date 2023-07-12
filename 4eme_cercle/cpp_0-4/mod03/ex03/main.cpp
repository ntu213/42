
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap playerA("playerA");
	DiamondTrap playerB("playerB");

	std::cout << '\n';
	playerA.attack(playerB.getName());
	playerB.takeDamage(playerA.getAttack());
	playerA.attack(playerB.getName());
	playerB.takeDamage(playerA.getAttack());
	std::cout << '\n';
	playerA.beRepaired(1);
	std::cout << '\n';
	playerB.attack(playerA.getName());
	playerA.takeDamage(playerB.getAttack());
	playerA.attack(playerB.getName());
	playerB.takeDamage(playerA.getAttack());
	std::cout << '\n';
	playerA.whoAmI();
	std::cout << '\n';
	return (0);
}