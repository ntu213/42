
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
		void	setName(std::string name);
		void	announce(void);
};