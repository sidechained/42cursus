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
		ASpell(std::string n, std::string e);
		ASpell(ASpell &obj);
		ASpell &operator=(const ASpell &obj);
		virtual ~ASpell();
		const std::string getName() const;
		const std::string getEffects() const;
		virtual ASpell *clone() const = 0;
		void launch(const ATarget &target) const;
};

#endif
