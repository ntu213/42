#include <iostream>

#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern & src);
		Intern & operator=(const Intern & src);
		Form * makeForm(std::string const type, std::string const target) const;
};

#endif
