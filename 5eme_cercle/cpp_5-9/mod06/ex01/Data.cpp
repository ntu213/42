
#include "Data.hpp"

Data::Data(): _name("Dat"), _secretData(0)
{
	std::cout << "Data " << _name << " created!" << std::endl;
}

Data::Data(std::string name): _name(name), _secretData(0)
{
	std::cout << "Data " << _name << " created!" << std::endl;
}

Data::~Data()
{
	std::cout << "Data " << _name << " deleted!" << std::endl;
}

Data::Data(Data & src): _name(src.getName()), _secretData(src.getSecretData())
{
	std::cout << "Data " << _name << " created by copy!" << std::endl;
}

Data & Data::operator=(Data & src)
{
	this->_name = src.getName();
	this->_secretData = src.getSecretData();
	std::cout << "Data " << this->_name << " copied!" << std::endl;
	return (*this);
}

std::string Data::getName() const
{
	return (this->_name);
}

int Data::getSecretData() const
{
	return (this->_secretData);
}

void Data::setSecretData(int n)
{
	this->_secretData = n;
}

