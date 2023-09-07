
#include "Infinite.hpp"

static bool ftIsWSpace(char c)
{
	int i = 0;
	std::string str = " \t\n\v\f\r";
	while (str[i])
	{
		if (str[i] == c)
			return (true);
		i++;
	}
	return (false);
}

std::string simplify(const std::string & str)
{
	std::string res = "";
	int i = 0;
	if (str[i] == '-')
		res.push_back(str[i++]);
	while (str[i] == '0')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
		res.push_back(str[i++]);
	if (!(res.length() && res[res.length() - 1] <= '9' && res[res.length() - 1] >= '0'))
		res.push_back('0');
	res.push_back('.');
	i++;
	int j = str.length() - 1;
	while (str[j] =='0')
		j--;
	while (i <= j)
		res.push_back(str[i++]);
	if (res[res.length() - 1] == '.')
		res.push_back('0');
	return (res);
}

static std::string checkValid(const std::string & str)
{
	int i = 0;
	bool dot = false;
	bool neg = false;
	std::string res = "";
	
	if (!str.length())
		std::out_of_range("Invalid Infinite input (0)");
	while (str[i] && ftIsWSpace(str[i]))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			neg = !neg;
		i++;
	}
	if (neg)
		res.push_back('-');
	while (str[i] && str[i] >= '0' && str[i]  <= '9')
		res.push_back(str[i++]);
	if (str[i] == '.' || str[i] == ',')
	{
		if (!i || str[i - 1] > '9' || str[i - 1] < '0')
			std::out_of_range("Invalid Infinite input (1)");
		res.push_back('.');
		dot = true;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i]  <= '9')
		res.push_back(str[i++]);
	if (str[i])
		std::out_of_range("Invalid Infinite input (2)");
	if (!dot)
		res.append(".0");
	return (simplify(res));
}

//  0: s1 == s2
// +X: s1 > s2
// -X: s1 < s2
int operators(const std::string & str1, const std::string & str2)
{
	std::string s1 = simplify(str1);
	std::string s2 = simplify(str2);
	int n = s1.compare(s2);
	if (s1[0] == '-' && s2[0] != '-')
		return (-1);
	if (s1[0] != '-' && s2[0] == '-')
		return (1);
	if (s1[0] == '-')
		n *= -1;
	return (n);
}

static int lastBeforeDot(const std::string & str)
{
	int i = 0;
	while (str[i] != '.')
		i++;
	return (i - 1);
}

static int countAfterDot(const std::string & str)
{
	return (str.length() - (lastBeforeDot(str) + 2));
}



Infinite::Infinite()
{
	this->nbr = "0.0";
}

/*
template <typename T>
Infinite::Infinite(const T & src)
{
	std::string tmp;
	const std::type_info& typeInfo = typeid(src);
	if (typeInfo == typeid(Infinite))
		tmp = src.get();
	else
		tmp = checkValid(std::string(src));
	this->nbr = tmp;
}
*/

Infinite::~Infinite()
{}

Infinite::Infinite(const Infinite & src)
{
	this->nbr = src.get();
}

Infinite::Infinite(const int & src)
{
	std::string tmp = checkValid(std::to_string(src));
	this->nbr = tmp;
}

Infinite::Infinite(const float & src)
{
	std::string tmp = checkValid(std::to_string(src));
	this->nbr = tmp;
}

Infinite::Infinite(const double & src)
{
	std::string tmp = checkValid(std::to_string(src));
	this->nbr = tmp;
}

Infinite::Infinite(const std::string & src)
{
	std::string tmp = checkValid(src);
	this->nbr = tmp;
}

const std::string & Infinite::get() const
{
	return (this->nbr);
}

Infinite & Infinite::operator=(const Infinite & src)
{
	this->nbr = src.get();
	return (*this);
}

template <typename T>
Infinite & Infinite::operator=(const T & src)
{
	std::string tmp = checkValid(std::string(src));
	this->nbr = tmp;
	return (*this);
}


bool Infinite::operator>(const Infinite & src) const
{
	int n = operators(this->nbr, src.get());
	if (n > 0)
		return (true);
	return (false);
}

bool Infinite::operator<(const Infinite & src) const
{
	int n = operators(this->nbr, src.get());
	if (n < 0)
		return (true);
	return (false);
}

bool Infinite::operator>=(const Infinite & src) const
{
	int n = operators(this->nbr, src.get());
	if (n > -1)
		return (true);
	return (false);
}

bool Infinite::operator<=(const Infinite & src) const
{
	int n = operators(this->nbr, src.get());
	if (n < 1)
		return (true);
	return (false);
}

bool Infinite::operator==(const Infinite & src) const
{
	int n = operators(this->nbr, src.get());
	if (!n)
		return (true);
	return (false);
}

bool Infinite::operator!=(const Infinite & src) const
{
	int n = operators(this->nbr, src.get());
	if (n)
		return (true);
	return (false);
}


Infinite Infinite::operator+(const Infinite & src) const
{
	int ret = 0;
	Infinite res(0);
	if (src.get()[0] == '-')
	{
		res = src;
		res.nbr.erase(0, 1);
		return (*this - res);
	}
	if (countAfterDot(this->nbr) == std::max(countAfterDot(this->nbr), countAfterDot(src.get())))
	{}
}

/*
Infinite Infinite::operator-(const Infinite & src) const
{
	Infinite res(0);
	if (src.get()[0] == '-')
	{
		res = src;
		res.nbr.erase(0, 1);
		return (*this - res);
	}
}

Infinite Infinite::operator*(const Infinite & src) const
{}

Infinite Infinite::operator/(const Infinite & src) const
{}

Infinite Infinite::operator%(const Infinite & src) const
{}
*/



std::ostream & operator<<( std::ostream & o, Infinite const & src )
{
	o << src.get();
	return (o);
}

