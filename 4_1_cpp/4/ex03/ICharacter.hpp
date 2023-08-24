#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class AMateria; // this has to be here otherwise "error: unknown type name 'AMateria'""

// By making all the member functions pure virtual, the ICharacter class specifies the required behavior for any character implementation.
// This creates a common interface that all character-related classes must adhere to. 
// Subclasses of ICharacter must implement all of these functions, ensuring they provide specific behavior for each function.
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