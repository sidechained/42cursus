#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class ICharacter
{
	private:
		std::string _name;
		AMateria* inventory[4];
		int currentMateria;
	public:
		ICharacter(std::string const &name);
		virtual ~ICharacter();
		ICharacter(const ICharacter &orig);
		virtual ICharacter	&operator=(const ICharacter &orig);
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif