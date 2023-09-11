#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{

}

void SpellBook::learnSpell(ASpell* s)
{
	if(!(book.find(s->getName()) != book.end()))
		book[s->getName()] = s->clone();
}

void SpellBook::forgetSpell(std::string const &sn)
{
	if(book.find(sn) != book.end())
		book.erase(book.find(sn));
}

ASpell* SpellBook::createSpell(std::string const &sn)
{
	if(book.find(sn) != book.end())
		return(book[sn]);
	return NULL;
}
