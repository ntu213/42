
#include <iostream>

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "Form.hpp"

class RobotomyRequestForm: public Form
{
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		int execute(Bureaucrat const & executor) const;
};

#endif
