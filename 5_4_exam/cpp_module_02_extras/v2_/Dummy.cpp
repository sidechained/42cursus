#include "Dummy.hpp"

Dummy::Dummy()
{
	type = "Target Practice Dummy";
}

Dummy::Dummy(Dummy &o)
{
	*this = o;
}

Dummy& Dummy::operator=(Dummy &o)
{
	this->type = o.type;
	return *this;
}

Dummy::~Dummy()
{

}

Dummy* Dummy::clone() const
{
	return new Dummy();
}
