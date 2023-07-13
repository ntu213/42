
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	std::cout << "\n-----------ANIMAL-----------\n" << '\n';

	const Animal* meta[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
	}
	for (int i = 0; i < 10; i++)
		meta[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete meta[i];

	std::cout << "\n--------WRONG ANIMAL--------\n" << '\n';

	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();
	std::cout << wi->getType() << " " << std::endl;
	std::cout << wmeta->getType() << " " << std::endl;
	wi->makeSound(); //will output the cat sound!
	wmeta->makeSound();
	delete wmeta;
	delete wi;

	return 0;
}
