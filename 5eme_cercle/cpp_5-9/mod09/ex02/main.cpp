
#include "PmergeMe.hpp"

void checker(int argc, char **argv)
{
	if (argc < 2)
		throw std::out_of_range("Not enough arguments");
	for (int i = 1; argv[i]; i++)
	{
		if (!argv[i][0])
			throw std::out_of_range("Invalid argument: " + std::string(argv[i]));
		for (int j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				throw std::out_of_range("Invalid argument: " + std::string(argv[i]));
		}
	}
}

int main(int argc, char **argv)
{
	try {
		checker(argc, argv);
		PmergeMe merge(argv);
	} catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
