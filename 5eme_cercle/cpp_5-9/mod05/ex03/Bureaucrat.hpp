
#include <iostream>

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"
class Form;

class Bureaucrat
{
	private:
		std::string name;
		int grade;
		Bureaucrat();
	public:
		Bureaucrat(std::string nam);
		Bureaucrat(std::string nam, int grad);
		Bureaucrat(const Bureaucrat & src);
		~Bureaucrat();
		Bureaucrat & operator=(const Bureaucrat & src);
		void setGrade(int n);
		void incrementGrade();
		void decrementGrade();
		std::string getName() const;
		int getGrade() const;
		void executeForm(Form const & form);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & src );

#endif