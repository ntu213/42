
#include <iostream>

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form
{
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		int execute(Bureaucrat const & executor) const;
};

#endif
