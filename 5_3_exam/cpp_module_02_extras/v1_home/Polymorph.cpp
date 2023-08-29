#include "Polymorph.hpp"

Polymorph::Polymorph()
{
	name = "Polymorph";
	effects = "turned into critter";
}

Polymorph::Polymorph(Polymorph &o)
{
	*this = o;
}

Polymorph& Polymorph::operator=(Polymorph &o)
{
	name = o.name;
	effects = o.effects;
	return *this;
}

Polymorph::~Polymorph()
{

}

ASpell* Polymorph::clone() const
{
	return new Polymorph();
}
