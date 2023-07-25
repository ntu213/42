
#include <iostream>

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

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