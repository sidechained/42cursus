#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include "SpellBook.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;
		SpellBook book;
	public:
		Warlock(std::string n, std::string t);
		~Warlock();
		Warlock(Warlock &obj);
		Warlock &operator=(Warlock &obj);		
		const std::string getName() const;
		const std::string getTitle() const;
		void setTitle(const std::string title_);
		void introduce() const;
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string spellName); // , and makes the Warlock forget it. If it's not a known spell, does nothing.
		void launchSpell(std::string spellName, ATarget &t); // launches the spell on the selected target. If it's not a known spell, does nothing.
};

#endif
