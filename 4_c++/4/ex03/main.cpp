// 5 classes:
// AMateria -> Ice/Cure
// ICharacter
// MateriaSource

// process:
// BUILT: IMateriaSource, AMateria and Ice
// commented out references to ICharacter in AMateria and Ice for now
// NOW BUILD ICharacter class


// NOW BUILD IMateriaSource, as according to main:
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// Expected output:
// $> clang++ -W -Wall -Werror *.cpp
// $> ./a.out | cat -e
// * shoots an ice bolt at bob *$ * heals bob's wounds *$

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	Ice* test_ice = new Ice(); // make new instance of Ice
	Cure* test_cure = new Cure(); // make new instance of Cure
	ICharacter* me = new Character("me");
	me->eqiup(test_ice);
	me->eqiup(test_cure);

	// Ice* test_ice = new Ice(); // make new instance of Ice
	// AMateria* cloneOfTest_ice; // make pointer of type Amateria, to point to cloned ice object, which will be an Amateria instance
	// std::string type_ice = test_ice->getType(); // get type of Ice instance
	// std::cout << type_ice << std::endl; // print type of Ice
	// cloneOfTest_ice = test_ice->clone(); // returns AMateria instance, is this what should happen?
	// std::string clonedType_ice = cloneOfTest_ice->getType(); // get type of clone
	// std::cout << clonedType_ice << std::endl; // print type of clone
	// std::cout << std::endl;

	// Cure* test_cure = new Cure(); // make new instance of Cure
	// AMateria* cloneOfTest_cure; // make pointer of type Amateria, to point to cloned ice object, which will be an Amateria instance
	// std::string type_cure = test_cure->getType(); // get type of Cure instance
	// std::cout << type_cure << std::endl; // print type of Cure
	// cloneOfTest_cure = test_cure->clone(); // returns AMateria instance, is this what should happen?
	// std::string clonedType_cure = cloneOfTest_cure->getType(); // get type of clone
	// std::cout << clonedType_cure << std::endl; // print type of clone
	// std::cout << std::endl;
	
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;
	// return 0;
}