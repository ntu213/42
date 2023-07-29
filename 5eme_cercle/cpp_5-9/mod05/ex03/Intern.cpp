
#include "Intern,hpp"

Form makeForm(std::string const type, std::string const target)
{
	if (type == "Presidential Pardon Form")
		return (PresidentialPardonForm(target));
	else if (type == "Robotomy Request Form")
		return (RobotomyRequestForm(target));
	else if (type == "Shrubbery Creation Form")
		return (ShrubberyCreationForm(target));
	std::cout << "What the heck is "
		<< type << "??\n";
	return (NULL);
}
