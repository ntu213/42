
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string nam)
{
	name = nam;
	grade = 150;
	std::cout << "The new recruit from grade "
		<< grade << ", "
		<< name << " just arrived!\n";
}

Bureaucrat::Bureaucrat(std::string nam, int grad)
{
	name = nam;
	setGrade(grad);
	std::cout << "The new "
		<< (grade > 100 ? "recruit" : (grade > 50 ? "hire" : "associate"))
		<< " from grade " << grade << ", "
		<< name << " just arrived!\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat & src)
{
	name = src.name;
	grade = src.grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Uh... I think " << this->name 
		<< " just jumped from the " << 151 - this->grade
		<< "th floor... Splaf!\n";
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & src)
{
	this->name = src.name;
	this->grade = src.grade;
	return (*this);
}

void Bureaucrat::setGrade(int n)
{
	try
	{
		if (n > 150)
			throw Bureaucrat::GradeTooLowException();
		if (n < 1)
			throw Bureaucrat::GradeTooHighException();
		this->grade = n;
		std::cout << "Hello "
			<< this->name << ", your grade is now "
			<< this->grade << ". Enjoy!\n";
	}
	catch (std::exception & e)
	{
		std::cout << "Hey! You can't do that! Let me explain: "
			<< e.what() << ".\n";
	}
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	this->setGrade(this->grade - 1);
}

void Bureaucrat::decrementGrade()
{
	this->setGrade(this->grade + 1);
}

void Bureaucrat::executeForm(Form const & form)
{
	if (form.execute(*this))
		std::cout << this->name << " executed "
			<< form.getName() << "\n";
	else
		std::cout << this->name << " can't execute "
			<< form.getName() << "\n";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("this grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("this grade is too low");
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & src )
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << ".\n";
	return (o);
}