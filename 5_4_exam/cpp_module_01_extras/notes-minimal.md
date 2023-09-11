# 0
w in Fwoosh should be lower case!

# 1

be sure to refence all .hpp files in head of main:
```
#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
```

# 2
constructor of ASpell should be in initialiser list form:
ASpell::ASpell(std::string n, std::string e) : name (n), effects (e)

# 3
Warlock hpp should include ASpell hpp
```
# include "ASpell.hpp"
```

# 4
no clone method in ASpell or ATarget

# 5
do forward declaration of ATarget in ASpell and also include "ATarget.hpp"
do forward declaration of ASpell in ATarget and also include "ASpell.hpp"

# 6
clone methods of Dummy should return ATarget
clone methods of Fwoosh should return ASpell

# 8
Dummy::Dummy() : ATarget("Target Practice Dummy")
FWoosh::FWoosh() : ASpell("Fwoosh", "fwooshed")
(must they be written like this?)

# 9
void learnSpell(ASpell *spell);

# 10
std::map < std::string, ASpell * > spellbook;
void Warlock::learnSpell(ASpell *spell)
{
	if(spell)
		spellbook[spell->getName()] = spell;
}

void Warlock::forgetSpell(std::string spellName)
{
	if(spellbook.find(spellName) != spellbook.end())
		spellbook.erase(spellbook.find(spellName));
}

void Warlock::launchSpell(std::string spellName, ATarget &target)
{
	if(spellbook.find(spellName) != spellbook.end())
		spellbook[spellName]->launch(target);
}
