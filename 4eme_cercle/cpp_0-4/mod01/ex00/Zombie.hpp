
#include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		std::string	getName();
		void	announce(void);
};