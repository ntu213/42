
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
	std::cout << "BURN " << this->name << " IN THE FIRE OF HELL\n";
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
}

std::string Form::getName()
{
	return (this->_name);
}

bool Form::getSigned()
{
	return (this->_signed);
}

int Form::getMin()
{
	return (this->_minGrade);
}

int Form::getMax()
{
	return (this->_maxGrade);
}

void Form::beSigned(const Bureaucrat & src) const
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
			<< this->name;
	}
	catch(const std::exception& e)
	{
		std::cout << src.getName() << " couldn't sign " << this->name << " because " << e.what() << '!\n';
	}
}

const std::string Form::GradeTooHighException::what() const throw()
{
	return ("this file underrates your grade permissions");
}

const std::string Form::GradeTooLowException::what() const throw()
{
	return ("this file overrates your grade permissions");
}

const std::string Form::AlreadySignedExeption::what() const throw()
{
	return ("there is already a signature here");
}
