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

Warlock::Warlock(Warlock &obj)
{
	*this = obj;
}

Warlock & Warlock::operator=(Warlock &obj)
{
	name = obj.name;
	title = obj.title;
	return *this;
}

const std::string Warlock::getName() const
{
	return name;
}

const std::string Warlock::getTitle() const
{
	return title;
}

void Warlock::setTitle(const std::string title_)
{
	title = title_;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	if(spell)
		spellbook[spell->getName()] = spell;
}

void Warlock::forgetSpell(std::string spellName)
{
	if(spellbook.find(spellName) != spellbook.end())
		spellbook.erase(spellbook.find(spellName));
}

void Warlock::launchSpell(std::string spellName, ATarget &target)
{
	if(spellbook.find(spellName) != spellbook.end())
		spellbook[spellName]->launch(target);
}
