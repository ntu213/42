
#include "Base.hpp"

/*
Base()
{
	std::cout << "Object Created" << std::endl;
}
*/

Base::~Base()
{
	std::cout << "Object Deleted" << std::endl;
}

/*
Base(Base & src)
{
	std::cout << "Object Created by Copy" << std::endl;
}

Base & operator=(Base & src)
{
	std::cout << "Object Copied" << std::endl;
	return (*this);
}
*/

