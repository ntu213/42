
#include "BitcoinExchange.hpp"
#include <cstring>
#include <utility>

static std::string ft_splitter_2(std::string const & str)
{
	std::string sep = "";
	int i = 0;

	while (str[i] && isalpha(str[i]))
		i++;
	if (!i)
		throw std::out_of_range("Invalid header");
	while (str[i] && str[i] != '\n' && !isalpha(str[i]))
	{
		sep.push_back(str[i++]);
	}
	int j = i;
	while (str[i] && str[i] != '\n')
		i++;
	if (i == j)
		throw std::out_of_range("Invalid header");
	return (sep);
}

template <typename T>
static void ft_print(T str)
{
	std::cout << "print: \"" << str << "\"" << std::endl;
}
/*
static std::string get_line(std::string const & str, int line)
{
	std::string res;
	int i = 0;
	int j = 0;
//		ft_print(str);
	while (str[i] && j < line)
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	while (str[i] && str[i] != '\n')
		res.push_back(str[i++]);
//	if (str[i])
//		res.push_back('\n');
	res.push_back('\0');
	return (res);
}
*/

std::string copyfrom(std::string const & str, int i)
{
	std::string res;
	while (str[i])
		res.push_back(str[i++]);
	return (res);
}

void ft_it(DataBase & db)
{
	for (std::map<std::string, float>::const_iterator it = db.getMap().begin();
		it != db.getMap().end(); it++)
		std::cout << "first: " << it->first << " sec: " << it->second << std::endl;
}

static void ft_splitter(DataBase & db, std::string & str, std::string sep)
{
	int j = 0;
	int k = 0;

	while (str[j])
	{
		k = 0;
		std::string index;
		std::string flot;
		while (str[j + k] && str[j + k] != '\n')
		{
			std::string tmp = copyfrom(str, j + k);
			while (std::strncmp(tmp.c_str(), sep.c_str(), sep.length()))
			{
				tmp = copyfrom(str, j + k);
				index.push_back(str[j + k]);
				k++;
			}
			index = index.substr(0, index.size() - 1);
			j += sep.length();
			while (str[j + k] && str[j + k] != '\n')
				flot.push_back(str[j+k++]);
			db[index] = atof(flot.c_str());
			ft_print(db[index]);
		}
		j += k + 1;
	}
}

static void filename_to_db(DataBase & db, std::string const & filename)
{
	std::fstream file;
	std::string str = "";
	char c[2];

	file.open(filename.c_str(), std::ios::in);
	file.read(c, 1);
	str.append(c);
	while (!file.eof())
	{
		file.read(c, 1);
		str.append(c);
	}
//	std::cout << str << std::endl;
	std::string separator;
	separator = ft_splitter_2(str);
	std::cout << "sep = \"" << separator << "\"" << std::endl;
	ft_splitter(db, str, separator);
}

int main(int argc, char **argv)
{
	DataBase db;
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Error: 2 arguments needed" << std::endl;
		return (1);
	}
	try
	{
		filename_to_db(db, "data.csv");
		filename_to_db(db, "data2.csv");
	} catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
