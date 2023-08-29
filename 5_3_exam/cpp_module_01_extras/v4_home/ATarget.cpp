#include "ATarget.hpp"

ATarget::ATarget()
{

}

ATarget::ATarget(std::string t)
{
	type = t;
}

ATarget::ATarget(ATarget &o)
{
	*this = o;
}

ATarget& ATarget::operator=(ATarget &o)
{
	this->type = o.type;
	return *this;
}

ATarget::~ATarget()
{

}
		
std::string ATarget::getType() const
{
	return type;
}

void ATarget::getHitBySpell(const ASpell &s) const
{
	std::cout << type << " has been " << s.getEffects() << "!" << std::endl;
}
