
#include "Span.hpp"

Span::Span(unsigned int n): _tab(std::array<int, n>), _size(n), _len(0)
{}

Span::Span(const Span & src) _tab(std::array(int, src.getSize())), _size(src.getSize()), _len(src.getLen())
{
	for (int i = 0; i < this->_len; i++)
		this->tab[i] = src.getTab()[i];
}

Span::~Span()
{}

Span & Span::operator=(const Span & src)
{}

void Span::addNumber(int n)
{
	this->_len < this->_size ? _tab[_len++] = n : throw std::exception("Span is full");
}

unsigned int Span::getSize() const
{
	return (this->_size);
}

int Span::getLen() const
{
	return (this->_len);
}

std::array<int> Span::getTab() const
{
	return (this->_tab);
}

static int abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int Span::shortestSpan()
{
	int res;
	if (this->_len < 2)
		throw std::exception("Span don't have enough arguments");
	res = abs(this->_tab[0] - this->_tab[1]);
	for (int i = 0; i < this->_len; i++){
		for (int j = i; j < this->_len; j++)
			if (abs(this->_tab[i] - this->_tab[j]) < res)
				res = abs(this->_tab[i] - this->_tab[j]);
	}
	return (res);
}

int Span::largestSpan()
{
	int res;
	if (this->_len < 2)
		throw std::exception("Span don't have enough arguments");
	res = abs(this->_tab[0] - this->_tab[1]);
	for (int i = 0; i < this->_len; i++){
		for (int j = i; j < this->_len; j++)
			if (abs(this->_tab[i] - this->_tab[j]) > res)
				res = abs(this->_tab[i] - this->_tab[j]);
	}
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
