#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	protected: // only accessible by this and derived classes

	public: // accessible by other classes
		Cure();
		~Cure();
		Cure(const Cure &orig);
		Cure	&operator=(const Cure &orig);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif