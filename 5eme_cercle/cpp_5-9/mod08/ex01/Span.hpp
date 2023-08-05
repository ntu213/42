
#include <iostream>

#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
	private:
		unsigned int _size;
		int _tab[];
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
		std::array<int> getTab() const;
		int shortestSpan();
		int largestSpan();
		void addRange(int n1, int n2);
};

#endif
