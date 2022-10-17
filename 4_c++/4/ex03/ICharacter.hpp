#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class AMateria; // this has to be here otherwise "error: unknown type name 'AMateria'""

class ICharacter
{
	public:
		virtual ~ICharacter() {} // empty function here so as not to have to make a cpp for ICharacter
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif