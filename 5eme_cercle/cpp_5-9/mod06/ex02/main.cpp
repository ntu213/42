
#include <cstdlib>
#include "Letter.hpp"

static void msg(std::string str)
{
	std::cout << str << std::endl;
}

Base *generate()
{
	int rdm = std::rand() % 3;
	switch (rdm)
	{
		case 0:
			msg("A generated");
			return (static_cast<Base*>(new A));
		case 1:
			msg("B generated");
			return (static_cast<Base*>(new B));
		default:
			msg("C generated");
			return (static_cast<Base*>(new C));
	}
}

void identify(Base *b)
{
	if (dynamic_cast<A*>(b))
		msg("A identified");
	else if (dynamic_cast<B*>(b))
		msg("B identified");
	else if (dynamic_cast<C*>(b))
		msg("C identified");
	else
		msg("Unknown type!");
}

void identify(Base & b)
{
	try
	{
		(void)dynamic_cast<A&>(b);
		msg("A identified");
		return ;
	} catch (std::exception & z) {}
	try
	{
		(void)dynamic_cast<B&>(b);
		msg("B identified");
		return ;
	} catch (std::exception & z) {}
	try
	{
		(void)dynamic_cast<C&>(b);
		msg("C identified");
		return ;
	} catch (std::exception & z) {}
	msg("Unknown type!");
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		Base *base = generate();
		Base &base2 = *base;
		identify(base);
		identify(base2);
		delete base;
		std::cout << std::endl;
	}
	return (0);
}
