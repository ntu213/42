
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		tab1.push_back(atoi(argv[i]));
		tab2.push(atoi(argv[i]));
	}
	std::vector<int> tmp;
	for (int i = 0; i < static_cast<int>(this->tab1.size()); i++)
	{
		for (int j = 0; j < static_cast<int>(tmp.size()); j++)
			if (tab1[i] == tmp[j])
				throw std::out_of_range("Double element detected");
		tmp.push_back(tab1[i]);
	}
	std::cout << "Before: [ ";
	for (int i = 0; i < static_cast<int>(this->tab1.size()); i++)
		std::cout << tab1[i] << " ";
	std::cout << "]" << std::endl;
	clock_t c1 = clock();
	this->sortVect();
	clock_t c2 = clock();
	timer1 = (double)(c2 - c1) / CLOCKS_PER_SEC * 1000;
	c1 = clock();
	this->sortVect();
	c2 = clock();
	timer2 = (double)(c2 - c1) / CLOCKS_PER_SEC * 1000;
	std::cout << "After:  [ ";
	for (int i = 0; i < static_cast<int>(this->tab1.size()); i++)
		std::cout << tab1[i] << " ";
	std::cout << "]" << std::endl;
	std::cout << "Time to process a range of "
		<< this->tab1.size() << " elements with std::vector: "
		<< timer1 << " us" << std::endl;
	std::cout << "Time to process a range of "
		<< this->tab2.size() << " elements with MutantStack (edited std::stack): "
		<< timer2 << " us" << std::endl;
}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(PmergeMe & src)
{
	for (int i = 0; i < static_cast<int>(src.tab1.size()); i++)
	{
		this->tab1.push_back(src.tab1[i]);
		this->tab2.push(src.tab2[i]);
	}
	this->timer1 = src.timer1;
	this->timer2 = src.timer2;
}

PmergeMe & PmergeMe::operator=(PmergeMe & src)
{
	for (int i = 0; i < static_cast<int>(src.tab1.size()); i++)
	{
		this->tab1.push_back(src.tab1[i]);
		this->tab2.push(src.tab2[i]);
	}
	this->timer1 = src.timer1;
	this->timer2 = src.timer2;
	return (*this);
}

void PmergeMe::sortVect()
{
	std::vector<int> res;
	res.push_back(*this->tab1.begin());
	for (int i = 1; i < static_cast<int>(this->tab1.size()); i++)
	{
		int j;
		for (j = 0; j < static_cast<int>(res.size()) && res[j] < tab1[i]; j++) {}
		res.insert(res.begin() + j, this->tab1[i]);
	}
	this->tab1 = res;
}

void PmergeMe::sortStack()
{
	MutantStack<int> res;
	res.push(*this->tab2.begin());
	for (int i = 1; i < static_cast<int>(this->tab2.size()); i++)
	{
		int j;
		for (j = 0; j < static_cast<int>(res.size()) && res[j] < tab2[i]; j++) {}
		res.insert(j, this->tab2[i]);
	}
	this->tab2 = res;
}
