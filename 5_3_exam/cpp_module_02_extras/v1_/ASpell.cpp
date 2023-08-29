#include "ASpell.hpp"

ASpell::ASpell(std::string n, std::string e)
{
	name = n;
	effects = e;
}

ASpell::ASpell(ASpell &obj)
{
	*this = obj;
}

ASpell &ASpell::operator=(ASpell &obj)
{
	this->name = obj.name;
	this->effects = obj.effects;
	return (*this);
}

ASpell::~ASpell()
{
	
}

std::string ASpell::getName() const
{
	return name;
}

std::string ASpell::getEffects() const
{
	return effects;
}

void ASpell::launch(const ATarget &a)
{
	a.getHitBySpell(*this);
}
