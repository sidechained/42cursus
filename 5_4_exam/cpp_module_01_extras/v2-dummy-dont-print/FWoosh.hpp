#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include "ASpell.hpp"

class FWoosh : public ASpell
{
	public:
		FWoosh();
		~FWoosh();
		ASpell *clone() const;
};		

#endif
