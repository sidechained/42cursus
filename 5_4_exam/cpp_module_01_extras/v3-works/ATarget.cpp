#include "ATarget.hpp"

ATarget::ATarget(std::string t)
{
	type = t;
}

ATarget::ATarget(ATarget &obj)
{
	*this = obj;
}

ATarget &ATarget::operator=(ATarget &obj)
{
	this->type = obj.type;
	return (*this);
}

ATarget::~ATarget()
{
	
}

std::string ATarget::getType() const
{
	return type;
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}
