
#include "Span.hpp"

void debug(std::string str, int n)
{
	std::cout << "debug " << str << " | " << n << std::endl;
}

Span::Span(unsigned int n): _size(n), _len(0)
{}

Span::Span(const Span & src): _size(src.getSize()), _len(src.getLen())
{
	for (int i = 0; i < this->_len; i++)
		this->_tab[i] = src.getTab()[i];
}

Span::~Span()
{}

Span & Span::operator=(const Span & src)
{
	this->_size = src.getSize();
	this->_len = src.getLen();
	for (int i = 0; i < this->_len; i++)
		this->_tab[i] = src.getTab()[i];
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->_len < static_cast<int>(this->_size))
	{
		_tab.push_back(n);
		_len++;
	} else
		throw std::out_of_range("Span is full");
}

unsigned int Span::getSize() const
{
	return (this->_size);
}

int Span::getLen() const
{
	return (this->_len);
}

std::vector<int> Span::getTab() const
{
	return (this->_tab);
}

/*
static int ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}
*/

int Span::shortestSpan()
{
	int res;
	if (this->_len < 2)
		throw std::out_of_range("Span don't have enough arguments");
	res = abs(this->_tab[0] - this->_tab[1]);
	for (int i = 0; i < this->_len; i++){
		for (int j = i + 1; j < this->_len; j++)
			if (abs(this->_tab[i] - this->_tab[j]) < res)
				res = abs(this->_tab[i] - this->_tab[j]);
	}
	return (res);
}

int Span::longestSpan()
{
	int res;
	if (this->_len < 2)
		throw std::out_of_range("Span don't have enough arguments");
	res = abs(*std::max_element(this->_tab.begin(), this->_tab.end()) - *std::min_element(this->_tab.begin(), this->_tab.end()));
	return (res);
}

void Span::addRange(int n1, int n2)
{
	int sign = 1;
	if (n1 > n2)
		sign *= -1;
	for (int i = 0; n1 + i != n2; i += sign){
		this->addNumber(n1 + i);
	}
}
