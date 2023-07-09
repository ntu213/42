
#include "HumanA.hpp"

HumanA::HumanA(std::string nam, Weapon & wp): name(nam), cudgel(wp)
{}

void	HumanA::attack()
{
	std::cout
		<< this->name
		<< " attacks with their "
		<< this->cudgel.getType() << '\n';
}
