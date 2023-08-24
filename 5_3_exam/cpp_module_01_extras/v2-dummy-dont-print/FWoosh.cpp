#include "FWoosh.hpp"

FWoosh::FWoosh() : ASpell("Fwoosh", "fwooshed")
{

}

FWoosh::~FWoosh()
{

}

ASpell *FWoosh::clone() const
{
	return (new FWoosh());
}

