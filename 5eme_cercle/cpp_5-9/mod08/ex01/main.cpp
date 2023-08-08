
#include "Span.hpp"
void debug(std::string str, int n);

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try
	{
//		sp.addRange(15, 13);
		std::cout << "Min: " << sp.shortestSpan() << std::endl;
		std::cout << "Max: " << sp.longestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
