#include "SpellBook.hpp"


SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{
    std::map<std::string, ASpell *>::iterator it_begin = this->book.begin();
    std::map<std::string, ASpell *>::iterator it_end = this->book.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    this->book.clear();
}

void SpellBook::learnSpell(ASpell* s)
{
	if(!(book.find(s->getName()) != book.end()))
		book[s->getName()] = s.clone();
}

void SpellBook::forgetSpell(std::string const &sn)
{
	if(book.find(sn) != book.end())
	{	
		delete(book.find(sn);
		book.erase(book.find(sn));
	}
}

ASpell* SpellBook::createSpell(std::string const &sn)
{
	ASpell *tmpSpell = NULL;
	if(book.find(sn) != book.end())
		tmpSpell = book[sn];
	return (tmpSpell);
}
