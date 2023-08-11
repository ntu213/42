
#include "BitcoinExchange.hpp"

DataBase::DataBase()
{}

DataBase::~DataBase()
{}

DataBase::DataBase(DataBase const & src)
{
	this->_map = src.getMap();
}

DataBase & DataBase::operator=(DataBase const & src)
{
	this->_map = src.getMap();
	return (*this);
}

float & DataBase::operator[](std::string const & str)
{
	return (this->_map[str]);
}

void DataBase::append(std::string str, float n)
{
	this->_map[str] = n;
}

std::map<std::string, float> const & DataBase::getMap() const
{
	return (this->_map);
}

float	DataBase::getValue(std::string key)
{
	for (std::map<std::string, float>::const_iterator it = this->_map.begin();
		it != this->_map.end(); it++)
	{
		std::cout << "len = " << key.length() << " | " << it->first.length() << std::endl;
		if ((*it).first == key)
		{
			std::cout << key << std::endl;
			return ((*it).second);
		}
	}
	return (-1);
}
