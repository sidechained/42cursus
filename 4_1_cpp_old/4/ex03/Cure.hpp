#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure &orig);
		Cure &operator=(const Cure &orig);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif