
#include <iostream>

#include "Bureaucrat.hpp"

#ifndef FORM_HPP
# define FORM_HPP

class Form
{
	private:
		std::string _name;
		bool _signed;
		int _rank;
		int _exec;
	public:
		Form();
		Form(std::string name);
		Form(std::string name, int rank, int exec);
		Form(const Form & src);
		~Form();
		Form & operator=(const Form & src);
		void beSigned(const Bureaucrat & src);
		std::string getName() const;
		bool getSigned() const;
		int getRank() const;
		int getExec() const;
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class AlreadySignedExeption: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream & operator<<( std::ostream & o, Form const & src );

#endif