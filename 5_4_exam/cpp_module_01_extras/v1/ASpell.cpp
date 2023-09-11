#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(std::string in_name, std::string in_effects)
{
	name = in_name;
	effects = in_effects;
}

ASpell::ASpell(const ASpell &a)
{
	*this = a;
}

ASpell &ASpell::operator=(const ASpell &a)
{
	name = a.name;
	effects = a.effects;
	return *this;
}

ASpell::~ASpell()
{

}

std::string ASpell::getName()
{
	return name;
}

std::string ASpell::getEffects() const
{
	return effects;
}

void ASpell::launch(const ATarget &t)
{
	t.getHitBySpell(*this);
}