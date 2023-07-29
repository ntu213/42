
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("Robotomy Request Form", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target): Form("Robotomy Request Form", 72, 45, target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

int RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > this->getExec())
			throw Form::GradeTooLowException();
		std::cout << "* Drill noises *" << std::endl;
		std::srand(std::time(0));
		sleep(2);
		if (std::rand() % 2)
			std::cout << this->getTarget() << " is now a cyborg! Why do you think the gatling-arm was a bad idea?\n";
		else
			std::cout << "I'm sorry, but I think the operation of your child failed. Do you want to sell him as spare parts?\n";
		return (1);
	}
	catch(const std::exception& e)
	{
		std::cout << this->getTarget() << " cannot execute this file: " << e.what() << "\n";
		return (0);
	}
}
