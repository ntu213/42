
#include <iostream>

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private:
		std::string _name;
		std::string _target;
		bool _signed;
		int _rank;
		int _exec;
	public:
		Form();
		Form(std::string name);
		Form(std::string name, int rank, int exec);
		Form(std::string name, int rank, int exec, std::string const target);
		Form(const Form & src);
		virtual ~Form();
		Form & operator=(const Form & src);
		void beSigned(const Bureaucrat & src);
		std::string getName() const;
		std::string getTarget() const;
		bool getSigned() const;
		int getRank() const;
		int getExec() const;
		virtual int execute(Bureaucrat const & executor) const;
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