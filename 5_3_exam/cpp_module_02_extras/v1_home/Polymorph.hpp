#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

#include "ASpell.hpp"

class Polymorph : public ASpell
{
	public:
		Polymorph();
		Polymorph(Polymorph &);
		Polymorph& operator=(Polymorph &);
		~Polymorph();
		ASpell* clone() const;
};

#endif
