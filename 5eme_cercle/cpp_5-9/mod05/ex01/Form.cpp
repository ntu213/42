
#include "Form.hpp"

Form::Form()
{
	_name = "Classic file";
	_signed = false;
	_minGrade = 150;
	_maxGrade = 1;
	std::cout << "Hey! I just stole "
		<< _name << " from the archives! let's take a look at this!\n";
}

Form::Form(std::string name)
{
	_name = name;
	_signed = false;
	_minGrade = 150;
	_maxGrade = 1;
	std::cout << "Hey! I just stole "
		<< _name << " from the archives! let's take a look at this!\n";
}

Form::Form(std::string name, int min, int max)
{
	_name = name;
	_signed = false;
	_minGrade = min;
	_maxGrade = max;
	std::cout << "Hey! I just stole "
		<< _name << " from the archives! let's take a look at this!\n";
}

Form::~Form()
{
	std::cout << "BURN " << this->_name << " IN THE FIRE OF HELL\n";
}

Form::Form(const Form & src)
{
	this->_name = src.getName();
	this->_signed = src.getSigned();
	this->_minGrade = src.getMin();
	this->_maxGrade = src.getMax();
}

Form & Form::operator=(const Form & src)
{
	this->_name = src.getName();
	this->_signed = src.getSigned();
	this->_minGrade = src.getMin();
	this->_maxGrade = src.getMax();
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getMin() const
{
	return (this->_minGrade);
}

int Form::getMax() const
{
	return (this->_maxGrade);
}

void Form::beSigned(const Bureaucrat & src)
{
	try
	{
		if (this->_signed)
			throw Form::AlreadySignedExeption();
		if (this->_maxGrade > src.getGrade())
			throw Form::GradeTooHighException();
		if (this->_minGrade < src.getGrade())
			throw Form::GradeTooLowException();
		_signed = true;
		std::cout << src.getName() << " just signed "
			<< this->_name << "\n";
	}
	catch(const std::exception& e)
	{
		std::cout << src.getName() << " couldn't sign " << this->_name << " because " << e.what() << "!\n";
	}
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("this file underrates grade permissions");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("this file overrates grade permissions");
}

const char *Form::AlreadySignedExeption::what() const throw()
{
	return ("there is already a signature here");
}
