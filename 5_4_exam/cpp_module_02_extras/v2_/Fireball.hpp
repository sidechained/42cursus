#ifndef FIREBALL_HPP
# define FIREBALL_HPP

#include "ASpell.hpp"

class Fireball : public ASpell
{
	public:
		Fireball();
		Fireball(Fireball &);
		Fireball& operator=(Fireball &);
		~Fireball();
		Fireball* clone() const;
};

#endif