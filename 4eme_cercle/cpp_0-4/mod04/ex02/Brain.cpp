
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "New Brain Generated! Thanks for using our services!\n";
}

Brain::~Brain()
{
	std::cout << "Uh! Another lost brain! let's give it to Franky!\n";
}

Brain::Brain(const Brain & src)
{
	*this = src;
}

Brain & Brain::operator=(const Brain & src)
{
	std::cout << "Telepathy in progress...";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	std::cout << " Done!";
	return (*this);
}
