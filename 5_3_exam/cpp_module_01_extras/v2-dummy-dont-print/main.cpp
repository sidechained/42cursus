#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "FWoosh.hpp"

int main()
{
	Warlock richard("Richard", "the Titled");

	Dummy bob;
	FWoosh* fwoosh = new FWoosh();

	richard.learnSpell(fwoosh);

	richard.introduce();
	richard.launchSpell("FWoosh", bob);

	richard.forgetSpell("FWoosh");
	richard.launchSpell("FWoosh", bob);
}
