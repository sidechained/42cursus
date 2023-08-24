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
	std::cout << std::endl;
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
	std::cout << "-3. Bob uses the four materias in his inventory on Jim" << std::endl;	
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
	std::cout << "-8. Delete jim (has no inventory to delete)" << std::endl;		
	delete jim;
	std::cout << std::endl;
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
	std::cout << "4. Create clones of the two new materias by passing their names as strings to createMateria()" << std::endl;
	AMateria* cloned_ice1 = materiaSource->createMateria("ice");
	AMateria* cloned_cure1 = materiaSource->createMateria("cure");
	std::cout << "5. Delete the original ice and cure" << std::endl;
	delete test_ice1; // this will expectedly cause leaks as materiaSource tries to delete it's materia's on destruction [comment out when clear about this test]
	delete test_cure1; // this will expectedly cause leaks as materiaSource tries to delete it's materia's on destruction [comment out when clear about this test]
	std::cout << "6. Get the type of the clones, they should still exist even though the originals have been deleted" << std::endl;
	std::cout << cloned_ice1->getType() << std::endl;
	std::cout << cloned_cure1->getType() << std::endl;	
	std::cout << "7. Showing that an unknown materia name passed to createMateria() returns 0" << std::endl;		
	std::cout << materiaSource->createMateria("flimflam") << std::endl;
	delete cloned_ice1;
	delete cloned_cure1;
	// delete materiaSource; // uncomment this when commenting out the above two lines
	std::cout << std::endl;
}

int main()
{
	providedTests();
	inventoryTests();
	MateriaSourceTests();
	return 0;
}