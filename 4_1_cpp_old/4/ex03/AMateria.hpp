#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter; // has to be there otherwise "error: unknown type name 'ICharacter'"

class AMateria
{
	private:
		AMateria(); // meet requirements of otherdox canonical form
	protected: // only accessible by this and derived classes	
		std::string _type;
	public:
		AMateria(std::string const &type);
		virtual ~AMateria();
		AMateria(const AMateria &orig);
		AMateria &operator=(const AMateria &orig);
		std::string const & getType() const; // Returns the materia type		
		virtual AMateria* clone() const = 0; // makes it pure virtual i.e. interface only
		virtual void use(ICharacter& target) = 0;
};

#endif