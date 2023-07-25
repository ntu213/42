
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat gerard = Bureaucrat("Gerard");
	Bureaucrat bernard = Bureaucrat("Bernard", 12);
	Bureaucrat eric = Bureaucrat("Eric", 121);

	std::cout << "Let's promote "
		<< gerard.getName() << "!\n";
	gerard.setGrade(10);
	std::cout << "Humm... "
		<< gerard.getGrade() << " is not enough\n";
	gerard.incrementGrade();
	std::cout << "Okay, "
		<< gerard.getGrade() << " is better\n";
	std::cout << "I think "
		<< eric.getName() << " deserve a demote\n";
	eric.decrementGrade();
	std::cout << "It's not enough!\n";
	eric.setGrade(180);
	std::cout << "Pfff...\n";
	return (0);
}
