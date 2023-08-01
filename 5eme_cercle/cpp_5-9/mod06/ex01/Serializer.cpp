
#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main()
{
	Data *dat = new Data();
	uintptr_t ptr;
	std::cout << "Data adress: " << dat << std::endl;
	ptr = Serializer::serialize(dat);
	std::cout << "Pointer adress: " << ptr << std::endl;
	std::cout << "Data adress: " << Serializer::deserialize(ptr) << std::endl;
	return (0);
}
