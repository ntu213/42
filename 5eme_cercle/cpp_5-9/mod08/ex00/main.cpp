
#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> v;
	v.push_back(15);
	v.push_back(42);
	try 
	{
		int n = easyfind(v, 15);
		std::cout << "n = " << n << std::endl;
		n = easyfind(v, 42);
		std::cout << "n = " << n << std::endl;
		n = easyfind(v, 213);
		std::cout << "n = " << n << std::endl;
	} catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
