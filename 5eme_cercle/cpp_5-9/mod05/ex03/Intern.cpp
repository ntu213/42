
#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern sumonned\n";
}

Intern::~Intern()
{
	std::cout << "Intern annihilated\n";
}

Intern::Intern(const Intern & src)
{
	(void)src;
	std::cout << "Intern cloned\n";
}

Intern & Intern::operator=(const Intern & src)
{
	(void)src;
	std::cout << "Intern copied\n";
	return (*this);
}


Form * Intern::makeForm(std::string const type, std::string const target) const
{
	if (type == "Presidential Pardon Form"
		|| type == "Robotomy Request Form"
		|| type == "Shrubbery Creation Form")
		std::cout << "Intern creates " << type << "\n";
	if (type == "Presidential Pardon Form")
		return (new PresidentialPardonForm(target));
	else if (type == "Robotomy Request Form")
		return (new RobotomyRequestForm(target));
	else if (type == "Shrubbery Creation Form")
		return (new ShrubberyCreationForm(target));
	std::cout << "What the heck is "
		<< type << "??\n";
	return (NULL);
}
