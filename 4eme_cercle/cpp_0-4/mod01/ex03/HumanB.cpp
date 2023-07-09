
#include "HumanB.hpp"

HumanB::HumanB()
{
	name = "Nemo";
	cudgel = NULL;
}

HumanB::HumanB(std::string nam)
{
	name = nam;
	cudgel = NULL;
}

void	HumanB::attack()
{
	
	std::cout
		<< this->name
		<< " attacks with their ";
	if (!this->cudgel)
		std::cout << "hands\n";
	else
		std::cout << this->cudgel->getType() << '\n';
}

void	HumanB::setWeapon(Weapon & wp)
{
	this->cudgel = &wp;
}
