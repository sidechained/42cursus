#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <string>
# include <map>

# include "ASpell.hpp"

class SpellBook
{
	private:
		SpellBook(SpellBook &);
		SpellBook& operator=(SpellBook &);
		std::map < std::string, ASpell * > book;
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell*);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);
};

#endif
