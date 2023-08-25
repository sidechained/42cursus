#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <string>
# include <map>
# include "ASpell.hpp"

class SpellBook
{
	private:
		SpellBook(SpellBook &obj);
		SpellBook& operator=(SpellBook &obj);
		std::map < std::string, ASpell*> book;
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string const &spellName);
		ASpell* createSpell(std::string const &spellName);
};

#endif