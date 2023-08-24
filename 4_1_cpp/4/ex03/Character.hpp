#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

// class AMateria; // this has to be here otherwise "error: unknown type name 'AMateria'""

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* inventory[4];
	public:
		Character(std::string const &name);
		~Character();
		Character(const Character &orig);
		Character &operator=(const Character &orig);
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		int	getNextEmptySlot();		
};

#endif