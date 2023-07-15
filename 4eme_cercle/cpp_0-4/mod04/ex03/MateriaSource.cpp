
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		mats[i] = NULL;
	copied = 0;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < copied; i++)
		if (mats[i])
			delete mats[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->copied == 4)
	{
		std::cout << "Not enough memory. Can't add another item\n";
		return ;
	}
	this->mats[this->copied] = m;
	std::cout << "Item added at memory slot " << this->copied++ << '\n';
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (!this->copied)
	{
		std::cout << "Memory is empty\n";
		return (NULL);
	}
	for (int i = 0; i < this->copied; i++)
	{
		if (this->mats[i]->getType() == type)
		{
			std::cout << "New item generated\n";
//			return (new AMateria(*this->mats[i]));
			return (this->mats[i]->clone());
		}
	}
	std::cout << "No item of type \"" << type << "\" in memory\n";
	return (NULL);
}
