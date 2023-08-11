
#include "BitcoinExchange.hpp"
#include <cstring>
#include <utility>

void ft_it(DataBase & db)
{
	for (std::map<std::string, float>::const_iterator it = db.getMap().begin();
		it != db.getMap().end(); it++)
		std::cout << "first: \"" << it->first << "\" sec: " << it->second << std::endl;
}

void fillWith(std::string & str, int n, char c)
{
	while(str[n])
	{
		str[n] = c;
		n++;
	}
}
/*
int isnumber(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}
*/

int getDate(std::string const & str, unsigned int n)
{
	std::string tmp;
	if (n > 2)
		throw std::out_of_range("Internal error");
	if (!n)
	{
		tmp = std::string(str.c_str());
		fillWith(tmp, 4, 0);
	}
	else if (n == 1)
	{
		tmp = std::string(str.c_str() + 5);
		fillWith(tmp, 2, 0);
	}
	else
	{
		tmp = std::string(str.c_str() + 7);
		fillWith(tmp, 2, 0);
	}
	return (atoi(tmp.c_str()));
}

/*
int str_format(std::string const & str, std::string const & format)
{
	int i = 0;
	while (str[i] && format[i])
	{
		if (format[i] == 'X' && !isnumber(str[i]))
			return (0);
		else if (format[i] != 'X' && format[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] || format[i])
		return (0);
	return (1);
}
*/

void addArg(DataBase & db, std::string & line, std::string sep)
{
	std::string str;
	int i;
	for (i = 0; line[i] && line[i] != sep[0]; i++)
		str.push_back(line[i]);
	if (str != "" && str != "date")
		db[str] = atof(line.c_str() + i + sep.length());
}

//void filename_to_db(DataBase & db, std::string const & filename)
//{}

void db_to_db(DataBase & db)
{
	std::fstream file;
	std::string str;
	char c[2];

	file.open("data.csv", std::ios::in);
	if (!file)
		throw std::out_of_range("Invalid file");
	file.read(c, 1);
	str.append(c);
	while (!file.eof())
	{
		file.read(c, 1);
		str.append(c);
	}
//	std::cout << "file= " << str << std::endl;
	for (int i = 0; str[i]; i++)
	{
		std::string line;
		while (str[i] && str[i] != '\n')
		{
			line.push_back(str[i]);
			i++;
		}
		addArg(db, line, ",");
	}
	(void)db;
}

int main(int argc, char **argv)
{
	DataBase db;
	DataBase db2;
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Error: 2 arguments needed" << std::endl;
		return (1);
	}
	try
	{
		db_to_db(db);
//		filename_to_db(db2, argv[1]);
		ft_it(db);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
//		calculator(db, db2);
//		calculator(db, db);
	} catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
