
#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
#include <cstdlib>

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef T* iterator;
		typedef T const* const_iterator;
		T & operator[](int n)
		{
			int i = 0;
			iterator it;
			for (it = this->begin(); it != this->end() && i < n; it++)
				i++;
			if (i != n)
				throw std::out_of_range("MutantStack: Invalid operand");
			return (*it);
		}
		void insert(int pos, T & src)
		{
			std::stack<T> tmp;
			while (this->size() > (long unsigned int)pos)
			{
				tmp.push(this->top());
				this->pop();
			}
			this->push(src);
			while (tmp.size())
			{
				this->push(tmp.top());
				tmp.pop();
			}
		}
		iterator begin()
		{
			int len = this->size();
			std::vector<T> v;
			iterator ret;
			while (!this->empty())
			{
				v.push_back(this->top());
				this->pop();
			}
			this->push(v[len-- - 1]);
			ret = &this->top();
			for (int i = 1; i <= len; i++)
				this->push(v[len - i]);
			return (ret);
		}
		iterator end() {return (&this->top() + 1);}
};

class PmergeMe
{
	private:
		PmergeMe();
	public:
		double timer1;
		double timer2;
		std::vector<int> tab1;
		MutantStack<int> tab2;
		PmergeMe(char **argv);
		~PmergeMe();
		PmergeMe(PmergeMe & src);
		PmergeMe & operator=(PmergeMe & src);
		void sortVect();
		void sortStack();
};

#endif
