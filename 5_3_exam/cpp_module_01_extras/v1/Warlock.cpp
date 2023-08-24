#include "Warlock.hpp"

Warlock::Warlock(std::string in_name, std::string in_title)
{
	name = in_name;
	title = in_title;
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

const std::string Warlock::getName() const
{
	return(name);
}

const std::string Warlock::getTitle() const
{
	return(title);
}

void Warlock::setTitle(const std::string in_title)
{
	title = in_title;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		spellbook[spell->getName()] = spell;
}

void Warlock::forgetSpell(std::string spell_to_forget)
{
	if (spellbook.find(spell_to_forget) != spellbook.end())
		spellbook.erase(spellbook.find(spell_to_forget));
}

void Warlock::launchSpell(std::string spell_to_launch, ATarget &target)
{
	if (spellbook.find(spell_to_launch) != spellbook.end())
		spellbook[spell_to_launch]->launch(target);
}
