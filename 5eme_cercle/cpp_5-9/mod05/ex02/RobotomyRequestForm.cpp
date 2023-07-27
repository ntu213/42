
#include "RobotomyRequestForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("Robotomy Request Form", 72, 45)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void execute(Bureaucrat const & executor) const
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
