#include "ASpell.hpp"

ASpell::ASpell(std::string n, std::string e) : name(n), effects(e)
{

}

ASpell::ASpell(ASpell &obj)
{
	*this = obj;
}

ASpell &ASpell::operator=(const ASpell &obj)
{
	name = obj.name;
	effects = obj.effects;
	return (*this);
}

ASpell::~ASpell()
{
	
}

const std::string ASpell::getName() const
{
	return name;
}

const std::string ASpell::getEffects() const
{
	return effects;
}

void ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}
