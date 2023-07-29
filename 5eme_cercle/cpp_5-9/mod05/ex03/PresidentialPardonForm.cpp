
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential Pardon Form", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target): Form("Presidential Pardon Form", 25, 5, target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

int PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > this->getExec())
			throw Form::GradeTooLowException();
		std::cout << this->getTarget() << " has been forgot by Zaphod Beeblebrox\n";
		return (1);
	}
	catch(const std::exception& e)
	{
		std::cout << this->getTarget() << " cannot execute this file: " << e.what() << "\n";
		return (0);
	}
}
