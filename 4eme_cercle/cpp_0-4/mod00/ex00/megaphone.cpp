#include <iostream>
#include <string>

std::string	ft_toupper(std::string str)
{
	int	i = 0;
	while (str[i])
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
	else
	{
		while (argv[i])
			std::cout << ft_toupper(argv[i++]);
		std::cout << "\n";
	}
	return (0);
}