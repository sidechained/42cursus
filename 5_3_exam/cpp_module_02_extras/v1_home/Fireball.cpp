#include "Fireball.hpp"

Fireball::Fireball()
{
	name = "Fireball";
	effects = "burnt to a crisp";
}

Fireball::Fireball(Fireball &o)
{
	*this = o;
}

Fireball& Fireball::operator=(Fireball &o)
{
	name = o.name;
	effects = o.effects;
	return *this;
}

Fireball::~Fireball()
{

}

ASpell* Fireball::clone() const
{
	return new Fireball();
}
