#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <string>
# include <map>

# include "ASpell.hpp"

class SpellBook
{
	private:
		std::map < std::string, ASpell * > book;
		SpellBook(const SpellBook&);
		SpellBook& operator=(const SpellBook&);
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell*);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);
};

#endif
