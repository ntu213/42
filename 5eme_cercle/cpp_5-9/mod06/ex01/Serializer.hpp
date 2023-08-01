
#include <iostream>
#include <stdint.h>

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(Serializer const & src);
		Serializer & operator=(Serializer const & src);
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
