
#include <iostream>

#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain& src);
		Brain& operator=(const Brain& src);
};

#endif