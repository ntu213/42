#include "ex01.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"


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