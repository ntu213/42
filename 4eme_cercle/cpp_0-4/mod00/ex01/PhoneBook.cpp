#include "PhoneBook.hpp"


std::string	ft_align(std::string str, int width)
{
	int	len = static_cast<int>(str.length());
	if (len <= width)
		return (std::string(width - len, ' ') + str);
	else
		return (str.substr(0, width - 1) + ".");
}


PhoneBook::PhoneBook()
{
	this->_last_added = 7;
	this->_total_contacts = 0;
//	this->contacts = new Contact[8];
//	for (int i = 0; i < 8; i++)
//		this->contacts[i] = Contact("", "", "", "", "");
};


void	PhoneBook::add_contact()
{
	std::string s1;
	std::string s2;
	std::string s3;
	std::string s4;
	std::string s5;

	this->_last_added++;
	this->_last_added %= 8;
	if (this->_total_contacts < 8)
		this->_total_contacts++;
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
	this->contacts[this->_last_added] = Contact(s1, s2, s3, s4, s5);
}


int	PhoneBook::print_contacts()
{
	int	i = 0;

	while (i < this->_total_contacts)
	{
		std::cout << "         " << i << "|"
		<< ft_align(this->contacts[i].get_first_name(), 10) << "|"
		<< ft_align(this->contacts[i].get_last_name(), 10) << "|"
		<< ft_align(this->contacts[i].get_nickname(), 10) << "\n";
		i++;
	}
	if (!i)
	{
		std::cout << "No contact entered yet\n";
		return (0);
	}
	return (1);
}


void	PhoneBook::ft_search()
{
	int	id;

	if (!this->print_contacts())
		return ;
	std::cout << "\nChoose a contact ID: ";
	std::cin >> id;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		id = -1;
	}
	if (id < 0 || id >= this->_total_contacts)
		std::cout << "[Error] Bad ID\n";
	else
		this->contacts[id].contact_print();
}