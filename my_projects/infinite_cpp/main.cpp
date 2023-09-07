
#include "Infinite.hpp"

std::string simplify(const std::string & str);
int operators(const std::string & s1, const std::string & s2);

int main()
{
	Infinite a = Infinite();
	Infinite b(15);
	Infinite c(a);
	Infinite d("15.3000");
	Infinite e(15.3);
	Infinite f("000015,3");

	a = b;
	b = e;
	e = c;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl;

	Infinite s1("-10.0");
	Infinite s2("-0000000010.00");

	std::cout << "operators: " << operators(s1.get(), s2.get()) << std::endl;
	std::cout << "operators: " << (s1 < s2) << std::endl;
	std::cout << "operators: " << (s1 > s2) << std::endl;
	std::cout << "operators: " << (s1 <= s2) << std::endl;
	std::cout << "operators: " << (s1 >= s2) << std::endl;
	std::cout << "operators: " << (s1 == s2) << std::endl;
	std::cout << "operators: " << (s1 != s2) << std::endl;

	std::cout << "simplify: " << simplify(s1.get()) << std::endl;
	std::cout << "simplify: " << simplify(s2.get()) << std::endl;
	s1 + s2;
	return (0);
}
