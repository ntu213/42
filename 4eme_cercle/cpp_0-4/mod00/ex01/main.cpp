#include "ex01.hpp"

/////PHONEBOOK/////

void	PhoneBook::add_contact()
{
	std::string s1;
	std::string s2;
	std::string s3;
	std::string s4;
	std::string s5;

	if (this->last_added == 8)
		this->last_added = 0;
	if (this->total_contacts < 8)
		this->total_contacts++;
	std::cout << "First Name: ";
	std::cin >> s1;
	std::cout << "Last Name: ";
	std::cin >> s2;
	std::cout << "Nickname: ";
	std::cin >> s3;
	std::cout << "Phone Number: ";
	std::cin >> s4;
	std::cout << "Darkest Secret: ";
	std::cin >> s5;
	this->contacts[this->last_added] = Contact(s1, s2, s3, s4, s5);
}

int	PhoneBook::print_contacts()
{
	int	i = 0;

	while (i < this->total_contacts)
	{
		std::cout << i << "|"
		<< ft_align(this->contacts[i].first_name, 10) << "|"
		<< ft_align(this->contacts[i].last_name, 10) << "|"
		<< ft_align(this->contacts[i].nickname, 10) << "\n";
		i++;
	}
	if (!i)
	{
		std::cout << "No contact entered yet\n";
		return (0);
	}
	return (1);
}


/////CONTACTS/////


void	Contact::contact_print()
{
	std::cout << "first_name" << this->first_name << "\n";
	std::cout << "last_name" << this->last_name << "\n";
	std::cout << "nickname" << this->nickname << "\n";
	std::cout << "phone" << this->phone << "\n";
	std::cout << "darkest_secret" << this->darkest_secret << "\n";
}


/////MAIN/////


std::string	ft_align(std::string str, int width)
{
	if (str.length() <= width)
		return (std::string(width - str.length(), ' ') + str);
	else
		return (str.substr(0, width - 1) + ".");
}

void	ft_error()
{
	std::cout << "[Error] Bad ID\n";
}

void	PhoneBook::ft_search()
{
	int	id;

	if (!this->print_contacts())
		return ;
	std::cout << "Choose a contact ID: ";
	std::cin >> id;
	if (id < 0 || id >= this->total_contacts)
		ft_error();
	this->contacts[id].contact_print();
}

int	main()
{
	PhoneBook	book;
	std::string	line;

	while (1)
	{
		std::cout << ">>>";
		std::cin >> line;
		if (line == "EXIT")
			break ;
		else if (line == "ADD")
			book.add_contact();
		else if (line == "SEARCH")
			book.ft_search();
	}
	return (0);
}