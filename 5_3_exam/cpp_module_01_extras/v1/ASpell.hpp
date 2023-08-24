#ifndef ASPELL_HPP
# define ASPELL_HPP
# include <iostream>

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;
	public:
		ASpell(std::string in_name, std::string in_effects);
		ASpell(const ASpell &a);
		ASpell &operator=(const ASpell &a);
		virtual ~ASpell();
		std::string getName();
		std::string getEffects() const;
		virtual ASpell* clone() = 0;
		void launch(const ATarget &t);
};

#endif