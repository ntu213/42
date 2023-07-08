#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone;
		std::string	_darkest_secret;
	public:
		Contact();
		~Contact();
		Contact(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5);
		void	contact_print();
		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		std::string	get_phone();
		std::string	get_darkest_secret();
};

#endif