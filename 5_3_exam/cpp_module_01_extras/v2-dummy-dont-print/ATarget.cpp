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
	type = obj.type;
	return *this;
}

ATarget::~ATarget()
{

}

const std::string ATarget::getType() const
{
	return type;
}

void ATarget::getHitBySpell(const ASpell &obj) const
{
	std::cout << type << " has been " << obj.getEffects() << "!" << std::endl;
}
