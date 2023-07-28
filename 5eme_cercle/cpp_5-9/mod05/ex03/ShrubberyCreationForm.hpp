
#include <iostream>
#include <fstream>

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		int execute(Bureaucrat const & executor) const;
};

#endif
