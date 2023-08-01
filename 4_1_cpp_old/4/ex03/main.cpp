// 5 classes: AMateria -> Ice/Cure, ICharacter, MateriaSource

// TODO: Copy or assignation of a Character must be deep, of course.
// TODO: The old Materia of a Character must be deleted - what do we mean by 'old materia'

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void providedTests()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

// testing clone method by cloning instance of Ice
// Clone is now of type AMateria, not Ice, but type variable is still "ice"
// TODO: if you clone an Ice Materia, you will get a new Ice Materia
void cloneTest()
{
	std::cout << "--- Materia Clone Test" << std::endl;
	Ice* test_ice = new Ice();
	std::cout << test_ice->clone()->getType() << std::endl;
}

void copyTests()
{
	//TODO
}

void inventoryTests()
{
	std::cout << "--- Character inventory test" << std::endl;
	std::cout << "-1. Create four new materias" << std::endl;
	Ice* test_ice1 = new Ice(); // make new instance of Ice
	Cure* test_cure1 = new Cure(); // make new instance of Cure
	Ice* test_ice2 = new Ice(); // make new instance of Ice
	Cure* test_cure2 = new Cure(); // make new instance of Cure
	std::cout << "-2. Create two new Characters (Bob and Jim)" << std::endl;
	Character* bob = new Character("bob");
	Character* jim = new Character("jim");
	std::cout << "-3. Bob equips the four materias" << std::endl;	
	bob->equip(test_ice1);
	bob->equip(test_cure1);
	bob->equip(test_ice2);
	bob->equip(test_cure2);
	std::cout << "-3. Bob uses the (4) materias in his inventory on Jim" << std::endl;	
	bob->use(0, *jim);
	bob->use(1, *jim);
	bob->use(2, *jim);
	bob->use(3, *jim);
	std::cout << "-4. Bob unequips the two cures (at indexes 1 and 3)" << std::endl;		
	bob->unequip(1);
	bob->unequip(3);
	std::cout << "-5. Bob uses the (now 2 ice) materias in his inventory on Jim" << std::endl;		
	bob->use(0, *jim);
	bob->use(1, *jim); // has no effect
	bob->use(2, *jim);
	bob->use(3, *jim); // has no effect
	std::cout << "-5. Bob re-equips the two cure materias, re-filling slots at indexes 1 and 3" << std::endl;		
	bob->equip(test_cure1);
	bob->equip(test_cure2);
	std::cout << "-6. Bob again uses the (4) materias in his inventory on Jim" << std::endl;	
	bob->use(0, *jim);
	bob->use(1, *jim);
	bob->use(2, *jim);
	bob->use(3, *jim);
	std::cout << "-7. Delete bob (and his inventory)" << std::endl;	
	delete bob;
	std::cout << "-8. Delete bob (has no inventory to delete)" << std::endl;		
	delete jim;
}

void MateriaSourceTests()
{
	std::cout << "--- MateriaSource test" << std::endl;
	std::cout << "1. Create two materias, ice and cure" << std::endl;		
	Ice* test_ice1 = new Ice();
	Cure* test_cure1 = new Cure();
	std::cout << "2. Create new MateriaSource" << std::endl;
	MateriaSource* materiaSource = new MateriaSource();
	std::cout << "3. MateriaSource learns the two new materias" << std::endl;	
	materiaSource->learnMateria(test_ice1);
	materiaSource->learnMateria(test_cure1);
	std::cout << "4. Creates clones of the two new materias by pass their names as strings to createMateria()" << std::endl;		
	std::cout << materiaSource->createMateria("ice")->getType() << std::endl;
	std::cout << materiaSource->createMateria("cure")->getType() << std::endl;
	std::cout << "5. Showing that an unknown materia name passed to createMateria() returns 0" << std::endl;		
	std::cout << materiaSource->createMateria("flimflam") << std::endl;		
}

int main()
{
	providedTests();
	// cloneTest();
	// copyTests();
	// inventoryTests();
	// MateriaSourceTests();
	return (0);
}