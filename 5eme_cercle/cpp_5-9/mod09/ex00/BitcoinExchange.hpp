
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <cstdlib>

#ifndef BTCEX_HPP
# define BTCEX_HPP

class DataBase
{
	private:
		std::map<std::string, float> _map;
	public:
		DataBase();
		~DataBase();
		DataBase(DataBase const & src);
		DataBase & operator=(DataBase const & src);
		float & operator[](std::string const & str);
		void append(std::string str, float n);
		std::map<std::string, float> const & getMap() const;
		float	getValue(std::string key);
};

#endif
