
#include <iostream>
#include <fstream>

void	ft_error(std::string str)
{
	std::cout << "[Error] " << str << '\n';
}

std::string	ft_search(std::string file, std::string s1, std::string s2)
{
	int	i = 0;
	int	j = 0;
	std::string tmp = " ";
	std::string res = "";

	while (file[i])
	{
		j = 0;
		while (file[i + j] && s1[j] && s1[j] == file[i + j])
			j++;
		tmp[0] = file[i];
		tmp[1] = 0;
		if (!s1[j])
		{
			i += j - 1;
			res.append(s2);
		}
		else
			res.append(tmp);
		i++;
	}
	return (res);
}

int main(int argc, char **argv)
{
	std::fstream	file;
	std::string		str = "";
	std::string		filename2;
	char c[2];

	if (argc != 4)
		return(ft_error("Bad Arguments"), 1);
	file.open(argv[1], std::ios::in);
	if (!file)
		return(ft_error("Invalid File"), 1);
	filename2 = argv[1];
	filename2.append(".replace");
	file.read(c, 1);
	while (!file.eof())
	{
		c[1] = 0;
		str.append(c);
		file.read(c, 1);
	}
	str = ft_search(str, argv[2], argv[3]);
	file.close();
	file.open(filename2.data(), std::ios::out);
	file << str;
	file.close();
	return (0);
}