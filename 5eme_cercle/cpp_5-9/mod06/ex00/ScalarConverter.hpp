
#include <iostream>
#include <cstdlib>
#include <limits.h>

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

class ScalarConverter
{
	private:
//		std::string _str;
		ScalarConverter();
//		ScalarConverter(std::string str);
		~ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter & operator=(ScalarConverter const & src);
	public:
//		std::string const & getStr() const;
		static void convert(std::string str);
};

#endif
