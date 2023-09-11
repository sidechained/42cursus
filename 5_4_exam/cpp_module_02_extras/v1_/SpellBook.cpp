#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{

}

// COPIES a spell in the book
void SpellBook::learnSpell(ASpell* spell)
{
   	if(spell)
		book[spell->getName()] = spell; 
}

// deletes a spell from the book, except if it isn't there
void SpellBook::forgetSpell(std::string const &spellName)
{
   	if(book.find(spellName) != book.end())
		book.erase(book.find(spellName)); 
}

// receives a string corresponding to the name of a spell, creates it, and returns it.
ASpell* SpellBook::createSpell(std::string const &spellName)
{
    ASpell* tmp = NULL;
	if (book.find(spellName) != book.end())
		tmp = book[spellName];
	return (tmp);
}
