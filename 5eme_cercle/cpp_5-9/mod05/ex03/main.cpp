
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat gerard("Gerard");
	Bureaucrat bernard("Bernard", 12);
	Bureaucrat eric("Eric", 121);
	Form classic;
	Form special("Special file");
	Form topSecret("Top Secret file", 30, 1);
	Form notSecret("Top Not Secret file", 140, 80);
	Form *pres;
	Form *robot;
	Form *tree;
	Intern littleGuy;

	std::cout << "\nLet's promote "
		<< gerard.getName() << "!\n";
	gerard.setGrade(10);
	std::cout << "Humm... "
		<< gerard.getGrade() << " is not enough\n";
	gerard.incrementGrade();
	std::cout << "Okay, "
		<< gerard.getGrade() << " is better\nNow you can sign this:\n";
	special.beSigned(gerard);
	std::cout << "I think "
		<< eric.getName() << " deserve a demote\n";
	eric.decrementGrade();
	std::cout << "It's not enough!\n";
	eric.setGrade(180);
	std::cout << "Pfff... Sign this!\n";
	notSecret.beSigned(eric);
	classic.beSigned(eric);
	topSecret.beSigned(eric);
	std::cout << "This one wasn't for you\nIntern! come here!\n";
	pres = littleGuy.makeForm("Presidential Pardon Form", "titi");
	robot = littleGuy.makeForm("Robotomy Request Form", "titi");
	tree = littleGuy.makeForm("Shrubbery Creation Form", "titi");
	littleGuy.makeForm("hehe i don't exist", "titi");
	std::cout << "Sorry, I have some things to execute!\n";
	gerard.executeForm(*pres);
	std::cout << "Huh, wait a second\n";
	gerard.setGrade(5);
	std::cout << "Okay, it must be fine\n";
	gerard.executeForm(*pres);
	gerard.executeForm(*tree);
	gerard.executeForm(*robot);
	std::cout << "OK finished!\n\n";

	delete pres;
	delete robot;
	delete tree;
	return (0);
}
