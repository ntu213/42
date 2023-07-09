
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon & cudgel;
	public:
		HumanA(std::string name, Weapon & wp);
		void attack();
};