#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{

}

// that COPIES a spell in the book
// same as Warlock::learnSpell
// might have to first check the spell exist i.e. if (spell)
void SpellBook::learnSpell(ASpell* s)
{
	if(!(book.find(s->getName()) != book.end()))
		book[s->getName()] = s;
}

// same as Warlock::forgetSpell
void SpellBook::forgetSpell(std::string const &sn)
{
	if(book.find(sn) != book.end())
		book.erase(book.find(sn));
}

// creates spell and returns it
ASpell* SpellBook::createSpell(std::string const &sn)
{
	ASpell* tmp = NULL;
	if (book.find(sn) != book.end())
		tmp = book[sn];
	return (tmp);
}
