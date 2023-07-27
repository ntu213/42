
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat gerard("Gerard");
	Bureaucrat bernard("Bernard", 12);
	Bureaucrat eric("Eric", 121);
	Form classic;
	Form special("Special file");
	Form topSecret("Top Secret file", 30, 1);
	Form notSecret("Top Not Secret file", 140, 80);

	std::cout << "Let's promote "
		<< gerard.getName() << "!\n";
	gerard.setGrade(10);
	std::cout << "Humm... "
		<< gerard.getGrade() << " is not enough\n";
	gerard.incrementGrade();
	std::cout << "Okay, "
		<< gerard.getGrade() << " is better\n Now you can sign this:\n";
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
	std::cout << "This one wasn't for you\n";
	return (0);
}
