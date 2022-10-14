#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected: // only accessible by this and derived classes	
		std::string _type;
	public: // accessible by other classes
		AMateria(std::string const &type);
		~AMateria();
		AMateria(const AMateria &orig);
		AMateria	&operator=(const AMateria &orig);
		std::string const & getType() const; // Returns the materia type		
		virtual AMateria* clone() const = 0; // makes it pure virtual i.e. interface only
		virtual void use(ICharacter& target);
};

#endif