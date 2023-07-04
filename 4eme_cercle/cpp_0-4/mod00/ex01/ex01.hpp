#ifndef EX01_HPP
# define EX01_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string	darkest_secret;
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone;
		Contact(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5)
		{
			first_name = s1;
			last_name = s2;
			nickname = s3;
			phone = s4;
			darkest_secret = s5;
		};
		void	contact_print();
};

class PhoneBook
{
	private:
		int		last_added = 8;
		int		total_contacts = 0;
	public:
		Contact	contacts[8];
		PhoneBook();
/*
		{
			last_added = 8;
			total_contacts = 0;
		};
*/
		void	add_contact();
		void	ft_search();
		int		print_contacts();
};

std::string	ft_align(std::string str, int width);

#endif