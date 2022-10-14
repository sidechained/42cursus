#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	protected: // only accessible by this and derived classes

	public: // accessible by other classes
		Ice();
		~Ice();
		Ice(const Ice &orig);
		Ice	&operator=(const Ice &orig);
		virtual AMateria* clone() const;
		//virtual void use(ICharacter& target);
};

#endif