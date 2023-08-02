
#include "whatever.hpp"

int main()
{
	int a = 42;
	int b = 21;
	float c = 42.5f;
	float d = 21.5f;

	std::cout << "a: " << a
		<< ", b: " << b
		<< ", c: " << c
		<< ", d: " << d << std::endl;
	swap(a, b);
	swap(c, d);
	std::cout << "a: " << a
		<< ", b: " << b
		<< ", c: " << c
		<< ", d: " << d << std::endl;
	std::cout << "min a b = " << min(a, b)
		<< ", max a b = " << max(a, b)
		<< "\nmin c d = " << min(c, d)
		<< ", max c d = " << max(c, d) << std::endl;
	return (0);
}
