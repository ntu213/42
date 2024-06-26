
#include "RPN.hpp"

void checkIllegal(std::string const & str)
{
	int i = 0;
	int nb = -1;
	int sym = 0;
	while (str[i])
	{
		if ((i % 2 && str[i] != ' ') || (i % 2 == 0 && str[i] == ' '))
			throw std::out_of_range("Bad spaces");
		else if (i % 2 == 0 && !((str[i] <= '9' && str[i] >= '0')
			|| str[i] == '+' || str[i] == '-'
			|| str[i] == '*' || str[i] == '/'))
			throw std::out_of_range("Bad character");
		if (str[i] <= '9' && str[i] >= '0')
			nb++;
		else if (str[i] == '+' || str[i] == '-'
			|| str[i] == '*' || str[i] == '/')
			sym++;
		i++;
	}
	if (nb > sym)
		throw std::out_of_range("Not enough symbols \"+-*/\"");
	if (nb < sym)
		throw std::out_of_range("Not enough numbers");
}

int doAct(int res, int n, char sym)
{
	if (sym == '+')
		res += n;
	else if (sym == '-')
		res -= n;
	else if (sym == '*')
		res *= n;
	else if (sym == '/')
		res /= n;
	else
		throw std::out_of_range("Unknown");
	return (res);
}

/*
void funcRPN(std::string str)
{
	std::queue<int> nb;
	std::queue<char> sym;
	checkIllegal(str);
	for (int i = 0; str[i]; i++)
	{
		if (!(i % 2))
		{
			if (str[i] <= '9' && str[i] >= '0')
				nb.push(str[i] - '0');
			else
				sym.push(str[i]);
		}
	}
	int res = nb.front();
	nb.pop();
	if (!nb.empty())
		std::cout << "Calcul detail:\n";
	while (!nb.empty())
	{
		std::cout << res << " "
			<< sym.front() << " "
			<< nb.front() << " = ";
		doAct(res, nb.front(), sym.front());
		std::cout << res << std::endl;
		nb.pop();
		sym.pop();
	}
	std::cout << "Result: " << res << std::endl;
}
*/

void funcRPN(std::string str)
{
	std::list<int> pile;
	checkIllegal(str);
	for (int i = 0; str[i]; i++)
	{
		if (!(i % 2))
		{
			if (str[i] <= '9' && str[i] >= '0')
				pile.push_front(str[i] - '0');
			else
			{
				if (pile.empty())
					throw std::out_of_range("Bad intentation");
				int tmp = pile.front();
				pile.pop_front();
				if (pile.empty())
					throw std::out_of_range("Bad intentation");
				int tmp2 = pile.front();
				pile.pop_front();
				int res = doAct(tmp, tmp2, str[i]);
				std::cout << tmp << str[i]
					<< tmp2 << " = "
					<< res << std::endl;
				pile.push_front(res);
			}
		}
	}
	std::cout << "Result: " << pile.front() << std::endl;
}

int main(int argc, char **argv)
{
	try {
		if (argc != 2)
			throw std::out_of_range("I need 2 arguments!");
		funcRPN(argv[1]);
	} catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
