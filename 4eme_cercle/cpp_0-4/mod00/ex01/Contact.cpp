#include "Contact.hpp"


Contact::Contact()
{
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone = "";
	this->_darkest_secret = "";
}


Contact::Contact(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5)
{
	this->_first_name = s1;
	this->_last_name = s2;
	this->_nickname = s3;
	this->_phone = s4;
	this->_darkest_secret = s5;
};


void	Contact::contact_print()
{
	std::cout << "first_name: " << this->_first_name << "\n";
	std::cout << "last_name: " << this->_last_name << "\n";
	std::cout << "nickname: " << this->_nickname << "\n";
	std::cout << "phone: " << this->_phone << "\n";
	std::cout << "darkest_secret: " << this->_darkest_secret << "\n";
}

std::string	Contact::get_first_name()
{
	return (this->_first_name);
}
std::string	Contact::get_last_name()
{
	return (this->_last_name);
}
std::string	Contact::get_nickname()
{
	return (this->_nickname);
}
std::string	Contact::get_phone()
{
	return (this->_phone);
}
std::string	Contact::get_darkest_secret()
{
	return (this->_darkest_secret);
}
