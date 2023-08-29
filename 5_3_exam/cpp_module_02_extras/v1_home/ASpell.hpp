#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>

# include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;
	public:
		ASpell();
		ASpell(std::string, std::string);
		ASpell(ASpell &);
		ASpell& operator=(ASpell &);
		~ASpell();
		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell *clone() const = 0;
		void launch(const ATarget &) const;
};

#endif
