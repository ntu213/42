
#include <iostream>

#ifndef DATA_HPP
# define DATA_HPP

struct Data
{
	private:
		std::string _name;
		int _secretData;
	public:
		Data();
		Data(std::string name);
		~Data();
		Data(Data & src);
		Data & operator=(Data & src);
		std::string getName() const;
		int getSecretData() const;
		void setSecretData(int n);
};

#endif
