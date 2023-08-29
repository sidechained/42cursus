#include "Warlock.hpp"

Warlock::Warlock(std::string n, std::string t)
{
	name = n;
	title = t;
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

std::string Warlock::getName() const
{
	return name;
}

std::string Warlock::getTitle() const
{
	return title;
}

void Warlock::setTitle(const std::string t)
{
	title = t;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *s)
{
	if(!(book.find(s->getName()) != book.end()))
		book[s->getName()] = s;
}

void Warlock::forgetSpell(std::string sn)
{
	if(book.find(sn) != book.end())
		book.erase(book.find(sn));
}

void Warlock::launchSpell(std::string sn, ATarget &t)
{
	if(book.find(sn) != book.end())
		book[sn]->launch(t);
}
