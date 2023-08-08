
#include <iostream>
#include <vector>
#include <algorithm>

#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
	private:
		unsigned int _size;
		std::vector<int> _tab;
		int _len;
		Span();
	public:
		Span(unsigned int n);
		Span(const Span & src);
		~Span();
		Span & operator=(const Span & src);
		void addNumber(int n);
		unsigned int getSize() const;
		int getLen() const;
		std::vector<int> getTab() const;
		int shortestSpan();
		int longestSpan();
		void addRange(int n1, int n2);
};

#endif
