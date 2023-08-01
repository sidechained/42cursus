#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice &orig);
		Ice	&operator=(const Ice &orig);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif