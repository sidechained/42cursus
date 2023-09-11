#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(std::string in_type)
{
	type = in_type;
}

ATarget::ATarget(const ATarget &a)
{
	*this = a;
}

ATarget &ATarget::operator=(const ATarget &a)
{
	type = a.type;
	return *this;
}

ATarget::~ATarget()
{

}

const std::string ATarget::getType() const
{
	return type;
}

// clone only implemented in derived class

void ATarget::getHitBySpell(const ASpell &a) const
{
	std::cout << type << " has been " << a.getEffects() << "!" << std::endl;
}