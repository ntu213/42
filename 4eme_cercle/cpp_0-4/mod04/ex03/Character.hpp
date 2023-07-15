
#include <iostream>
#include "AMateria.hpp"

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
class AMateria;

class Character
{
	private:
	protected:
		std::string name;
		AMateria *inv[4];
		int	items;
	public:
		Character();
		Character(std::string nam);
		virtual ~Character();
		virtual std::string const & getName();
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, Character& target);
};

#endif