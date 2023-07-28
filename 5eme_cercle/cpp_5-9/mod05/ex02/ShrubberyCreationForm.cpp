
#include "ShrubberyCreationForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("Shrubbery Creation Form", 145, 137)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

static std::string & ft_tree()
{
	std::string tree = "";
	tree.append("            ,@@@@@@@,\n");
	tree.append("    ,,,.   ,@@@@@@/@@,  .oo8888o.\n");
	tree.append(" ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n");
	tree.append(",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n");
	tree.append("%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n");
	tree.append("%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n");
	tree.append("`&%\\ ` /%&'    |.|        \\ '|8'\n");
	tree.append("    |o|        | |         | |\n");
	tree.append("    |.|        | |         | |\n");
	tree.append(" \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n");
	return (tree);
}

int ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::fstream file;
	std::string filename;

	filename = executor.getName();
	filename.append("_shrubbery");
	try
	{
		if (executor.getGrade() > this->getExec())
			throw Form::GradeTooLowException();
		file.open(filename, std::ios::out | std::ios::trunc);
		file << ft_tree();
		file.close();
		return (1);
	}
	catch(const std::exception& e)
	{
		std::cout << executor.getName() << " cannot execute this file: " << e.what() << "\n";
		return (0);
	}
}
