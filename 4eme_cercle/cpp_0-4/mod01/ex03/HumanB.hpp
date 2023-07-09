
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *cudgel;
	public:
		HumanB();
		HumanB(std::string name);
		void attack();
		void setWeapon(Weapon & wp);
};