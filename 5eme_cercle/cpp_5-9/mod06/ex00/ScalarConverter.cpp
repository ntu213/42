
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
//	_str = str;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	(void)src;
//	_str = src.getStr();
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src)
{
	(void)src;
//	this->_str = src.getStr();
	return (*this);
}

/*
static float ft_modulo(float f, float n)
{
	while (f - n >= 0)
		f -= n;
	return (f);
}
*/

void ScalarConverter::convert(std::string str)
{
	int c2 = 0;
	if (str.length() == 1)
		c2 = str[0];
	else if (str.length() > 1 && (!(str[0] >= '0' && str[0] <= '9') && str[0] != '.'))
		c2 = -1;
	else
	{
		int tmp = 0;
		for (long unsigned int i = 0; i < str.length(); i++)
			if (str[i] == '.')
				tmp++;
		if (tmp > 1)
			c2 = -1;
	}

	if (c2 < 0)
	{
		std::cout << "Nope!" << std::endl;
		return ;
	}


	int c = atoi(str.c_str());
	if (c2)
		c = c2;
	std::cout << "Char: ";
	if (c <= 126 && c >= 33)
		std::cout << (char)c;
	else
		std::cout << ((c < 0 || c > 127) ? "impossible" : "non displayable");
	std::cout << std::endl;


	long n = atol(str.c_str());
	if (c2)
		n = c2;
	std::cout << "Int: ";
	if (str == "nan" || str == "nanf"
		|| str == "-inf" || str == "-inff"
		|| str == "inf" || str == "inff"
		|| str == "+inf" || str == "+inff"
		|| n > INT_MAX || n < INT_MIN)
		std::cout << "impossible";
	else
		std::cout << n;
	std::cout << std::endl;


	float f = atof(str.c_str());
	if (c2)
		f = c2;
	std::cout << "Float: "
		<< f << (f - (float)(int)f ? "f" : ".0f")
		<< std::endl;


	double d = strtod(str.c_str(), NULL);
	if (c2)
		d = c2;
	std::cout << "Double: " << d
		<< (d - (double)(int)d ? "" : ".0") << std::endl;
}



int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: bad arguments" << std::endl;
		return (1);
	}
	std::string str = argv[1];
	ScalarConverter::convert(str);
	return (0);
}
