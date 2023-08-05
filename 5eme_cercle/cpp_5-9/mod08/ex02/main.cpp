
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(6);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	int i = 0;
	while (it != ite)
	{
		std::cout << "Index " << i << ": " << *it << std::endl;
		i++;
		++it;
	}
	std::stack<int> s(mstack);

	return 0;
}
