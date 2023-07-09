
#include <iostream>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout
		<< &str << '\n'
		<< strPTR << '\n'
		<< &strREF << '\n';

	std::cout
		<< str << '\n'
		<< *strPTR << '\n'
		<< strREF << '\n';

	return (0);
}