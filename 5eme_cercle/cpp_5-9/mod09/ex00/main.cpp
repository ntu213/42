
#include "BitcoinExchange.hpp"
#include <cstring>
#include <utility>

/*****************************UTILS******************************/

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

int isnumber(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

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
		tmp = std::string(str.c_str() + 8);
		fillWith(tmp, 2, 0);
	}
	return (atoi(tmp.c_str()));
}

int compareDate(std::string const & d1, std::string const & d2) // 0 si d1 < d2, 1 si d1 > d2, 2 si d1 == d2
{
	if (getDate(d1, 0) < getDate(d2, 0))
		return (0);
	else if (getDate(d1, 0) > getDate(d2, 0))
		return (1);

	if (getDate(d1, 1) < getDate(d2, 1))
		return (0);
	else if (getDate(d1, 1) > getDate(d2, 1))
		return (1);

	if (getDate(d1, 2) < getDate(d2, 2))
		return (0);
	else if (getDate(d1, 2) > getDate(d2, 2))
		return (1);

	return (2);
}

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

int sherpa(std::string & line, int i, std::string sep)
{
	int j = i;
	while (line[i])
		i++;
	if (i < (j + (int)sep.length() + 1))
		return (0);
	return (1);
}

void addArg(DataBase & db, std::string & line, std::string sep)
{
	std::string str;
	int i;

	for (i = 0; line[i] && line[i] != sep[0]; i++)
		str.push_back(line[i]);
	if (str != "" && str != "date")
		db[str] = atof(line.c_str() + i + sep.length());
	if (str != "" && str != "date" && !sherpa(line, i, sep))
		db[str] = -1;
}

/*****************************PART*2*****************************/

DataBase filename_to_db(char const *filename)
{
	std::fstream file;
	std::string str;
	char c[2];
	DataBase	db;

	file.open(filename, std::ios::in);


	if (!file)
		throw std::out_of_range("Invalid file");
	file.read(c, 1);
	str.append(c);
	while (!file.eof())
	{
		file.read(c, 1);
		str.append(c);
	}
	file.close();
	for (int i = 0; i < (int)str.length(); i++)
	{
		std::string line;
		while (str[i] && str[i] != '\n')
		{
			line.push_back(str[i]);
			i++;
		}
		addArg(db, line, " | ");
	}
	return (db);
}

/*****************************PART*1*****************************/

DataBase db_to_db()
{
	DataBase	db;
	std::fstream file;
	std::string str;
	char c[2];

	file.open("data.csv", std::ios::in);
	if (!file)
		throw std::out_of_range("Hey! I need my database! Gimme it back!");
	file.read(c, 1);
	str.append(c);
	while (!file.eof())
	{
		file.read(c, 1);
		str.append(c);
	}
	file.close();
	//std::cout << "file= " << str << std::endl;
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
	return (db);
}

/***************************CALCULATOR***************************/

void calCheck(std::string const str, float const f)
{
	if (f > 1000 || f < 0)
		throw std::out_of_range("Unaccepted number");
	if (!(str_format(str, "XXXX-XX-X") || str_format(str, "XXXX-XX-XX")))
		throw std::out_of_range("Invalid date or separator");
//	std::cout << "ErrM: " << getDate(str, 0) << std::endl;
//	std::cout << "ErrM: " << getDate(str, 1) << std::endl;
//	std::cout << "ErrM: " << getDate(str, 2) << std::endl;
	if (getDate(str, 1) > 12 || getDate(str, 1) < 1
		|| getDate(str, 2) > 31 || getDate(str, 2) < 1)
		throw std::out_of_range("Invalid date");
}

void calculator(DataBase & db1, DataBase & db2, int n)
{
	for (std::map<std::string, float>::const_iterator it = db2.getMap().begin();
		it != db2.getMap().end(); it++)
	{
		std::map<std::string, float>::const_iterator it2;
		for (it2 = db1.getMap().begin(); it2 != db1.getMap().end() && !compareDate(it2->first, it->first); it2++)
		{}
		if (it2 == db1.getMap().end())
			it2--;
		try {
			if (n)
				calCheck(it->first, it->second);
			std::cout << it->first << " => "
				<< it->second << " = "
//				<< it->second << " * " << it2->second << " = "
				<< it->second * it2->second << std::endl;
//				printf("%0.2f\n", it->second * it2->second);
		} catch (std::exception & e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

/******************************MAIN******************************/

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
		db = db_to_db();
//		ft_it(db);
//		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		db2 = filename_to_db(argv[1]);
//		ft_it(db2);
//		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
//		calculator(db, db2, 0);
//		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		calculator(db, db2, 1);
//		calculator(db, db);
	} catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
