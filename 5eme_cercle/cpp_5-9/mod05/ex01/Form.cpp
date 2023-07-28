
#include "Form.hpp"

Form::Form()
{
	_name = "Classic file";
	_signed = false;
	_rank = 150;
	_exec = 150;
	std::cout << "Hey! I just stole "
		<< _name << " from the archives! Let's take a look at this!\n";
}

Form::Form(std::string name)
{
	_name = name;
	_signed = false;
	_rank = 150;
	_exec = 150;
	std::cout << "Hey! I just stole "
		<< _name << " from the archives! Let's take a look at this!\n";
}

Form::Form(std::string name, int rank, int exec)
{
	_name = name;
	_signed = false;
	_rank = rank;
	_exec = exec;
	std::cout << "Hey! I just stole "
		<< _name << " from the archives! Let's take a look at this!\n";
}

Form::~Form()
{
	std::cout << "BURN " << this->_name << " IN THE FIRE OF HELL\n";
}

Form::Form(const Form & src)
{
	this->_name = src.getName();
	this->_signed = src.getSigned();
	this->_rank = src.getRank();
	this->_exec = src.getExec();
	std::cout << this->_name << " has been copied";
}

Form & Form::operator=(const Form & src)
{
	this->_name = src.getName();
	this->_signed = src.getSigned();
	this->_rank = src.getRank();
	this->_exec = src.getExec();
	std::cout << this->_name << " has been copied";
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

int Form::getRank() const
{
	return (this->_rank);
}

int Form::getExec() const
{
	return (this->_exec);
}

void Form::beSigned(const Bureaucrat & src)
{
	try
	{
		if (this->_signed)
			throw Form::AlreadySignedExeption();
		if (this->_rank < src.getGrade())
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

const char *Form::GradeTooLowException::what() const throw()
{
	return ("this file overrates grade permissions");
}

const char *Form::AlreadySignedExeption::what() const throw()
{
	return ("there is already a signature here");
}

std::ostream & operator<<( std::ostream & o, Form const & src )
{
	o << src.getName() << " is "
		<< (src.getSigned() ? "signed" : "unsigned")
		<< ", needs grade " << src.getRank()
		<< " to be signed and grade " << src.getExec()
		<< " to be executed";
	return (o);
}
