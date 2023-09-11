#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
{
	name = "Fwoosh";
	effects = "fwooshed";
}

Fwoosh::Fwoosh(Fwoosh &o)
{
	*this = o;
}

Fwoosh& Fwoosh::operator=(Fwoosh &o)
{
	name = o.name;
	effects = o.effects;
	return *this;
}

Fwoosh::~Fwoosh()
{

}

Fwoosh* Fwoosh::clone() const
{
	return new Fwoosh();
}
