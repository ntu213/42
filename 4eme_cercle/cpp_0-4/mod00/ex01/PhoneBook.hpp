#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <iostream>
# include <string>

# include "Contact.hpp"

class PhoneBook
{
	private:
		int		_last_added;
		int		_total_contacts;
		Contact	contacts[8];
	public:
		PhoneBook();
		void	add_contact();
		void	ft_search();
		int		print_contacts();
};

#endif