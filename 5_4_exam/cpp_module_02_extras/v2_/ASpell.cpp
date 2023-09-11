#include "ASpell.hpp"

ASpell::ASpell()
{

}

ASpell::ASpell(std::string n, std::string e)
{
	name = n;
	effects = e;
}

ASpell::ASpell(ASpell &o)
{
	*this = o;
}

ASpell& ASpell::operator=(const ASpell &o)
{
	this->name = o.name;
	this->effects = o.effects;
	return *this;
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

void ASpell::launch(const ATarget &t) const
{
	t.getHitBySpell(*this);
}
