
#include <iostream>
#include <stack>
#include <vector>

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef T* iterator;
		typedef T const* const_iterator;
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

#endif
