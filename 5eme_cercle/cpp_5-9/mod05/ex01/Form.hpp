
#include <iostream>

#include "Bureaucrat.hpp"

#ifndef FORM_HPP
# define FORM_HPP

class Form
{
	private:
		std::string _name;
		bool _signed;
		int _minGrade;
		int _maxGrade;
	public:
		Form();
		Form(std::string name);
		Form(std::string name, int min, int max);
		Form(const Form & src);
		~Form();
		Form & operator=(const Form & src);
		void beSigned(const Bureaucrat & src) const;
		std::string Form::getName();
		bool Form::getSigned();
		int Form::getMin();
		int Form::getMax();
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const std::string what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const std::string what() const throw();
		};
		class AlreadySignedExeption: public std::exception
		{
			public:
				virtual const std::string what() const throw();
		};
};

std::ostream & operator<<( std::ostream & o, Form const & src );

#endif