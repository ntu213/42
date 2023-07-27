
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential Pardon Form", 25, 5)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

int execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > this->getExec())
			throw Form::GradeTooLowException();
		std::cout << executor.getName() << " has been forgot by Zaphod Beeblebrox\n";
		return (1);
	}
	catch(const std::exception& e)
	{
		std::cout << executor.getName() << " cannot execute this file: " << e.what() << "\n";
		return (0);
	}
}
