# ex01 - things to remember when writing again from scratch!

- derived classes must not have copy constructors or assignment operator overloads (presumably these are inherited)
- derived classes must have empty destructors within them, as the destructor in the class they are derived from is declared as virtual

- Fwoosh must explicitly call the constructor of ASpell in initialiser list form i.e.:
`Fwoosh::Fwoosh() :  ASpell("Fwoosh", "fwooshed")`
- Dummy must explicitly call the constructor of ATarget in initialiser list form i.e.:
`Dummy::Dummy() : ATarget("Target Practice Dummy")`

- destructors in abstract classes ASpell and ATarget should be virtual but not in derived classes Warlock, Fwoosh or Dummy

- clone methods 
-- should be declared in the header of the a classes as pure virtual (= 0)
-- should not be implemented in the abstract class, only in the derived class
-- the return type in the derived class should be the type of the abstract class i.e.
--- return type of clone method in Fwoosh should be ASpell* 
--- return type of clone method in Dummy should be ATarget*

- if another form of constructor is requested for a class (i.e. with args) there is no need to implement the default constructor

- all methods of all classes should be public apart from in Warlock where the default contructor, copy constructor and assignment operator overload are not (not sure why)

- a map or vector can be used to contain spells in Warlock. Maps:
-- allows for key-value storage
-- need `# include <map>` in header
-- are declared as `std::map < std::string, ASpell * > spellbook;`
-- where `std::string, ASpell *` are the types of the keys and values
-- and `spellbook` will be the name of the map
-- in learnSpell:
```
	if (spell)
		spellbook[spell->getName()] = spell;
```
-- in forgetSpell we use find to 
```
	if (spellbook.find(spellname) != spellbook.end())
		spellbook.erase(spellbook.find(spellname));
-- in launchSpell:
```
	if (spellbook.find(spellname) != spellbook.end())
		spellbook[spellname]->launch(target);
```

Q: what is LittleKid.hpp/cpp and why does name of 2nd exercise differ?
