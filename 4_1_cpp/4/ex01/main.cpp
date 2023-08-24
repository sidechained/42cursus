#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void constructDestructTest()
{
	const Animal* animalArray[BRAINSIZE];

	std::cout << "-- Testing Construction and Destruction:" << std::endl;
	for (int i = 0; i < BRAINSIZE/2; i++)
	{
		std::cout << i << ": ";
		animalArray[i] = new Dog();
		std::cout << std::endl;
	}
	for (int i = (BRAINSIZE/2); i < BRAINSIZE; i++)
	{
		std::cout << i << ": ";
		animalArray[i] = new Cat();
		std::cout << std::endl;
	}
	for (int i = 0; i < BRAINSIZE; i++)
	{
		std::cout << i << ": ";
		animalArray[i]->makeSound();
		std::cout << std::endl;
	}
	for (int i = 0; i < BRAINSIZE; i++)
	{
		std::cout << i << ": ";		
		delete animalArray[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// Tests if copying Cat also copies state of base class Animal, by:
// - creating instance of Cat and copying it (either by copy constructor or assignment operator)
// - calling getType() method (which belongs only to Animal class) to see if it returns 'Cat'
// - also calling other methods that belong to cat, for confirmation

// Testing whether a copy is deep or shallow involves verifying whether the copied object has its independent copy of dynamically allocated resources
// or if it merely shares the same resources with the original object.

void deepCopiesTest()
{
	std::cout << "-- Testing if copies are 'deep':" << std::endl;

	// TESTING COPY CONSTRUCTOR
	std::cout << "- COPYING Cat using Copy Constructor:" << std::endl;
	std::cout << "Cats constructing: ";
	std::cout << std::endl;
	const Cat* original1 = new Cat();
	std::cout << std::endl;
	const Cat* copy1 = new Cat(*original1);
	std::cout << std::endl;	
	std::cout << "Delete the original: " << std::endl;
	delete original1;
	std::cout << "Copycat should still have a brain!: " << std::endl;
	copy1->getBrain()->sayFirstIdea();
	std::cout << "Delete the copy: " << std::endl;
	delete copy1;
	std::cout << std::endl;
	std::cout << std::endl;

	// TESTING ASSIGNMENT OPERATOR
	std::cout << "- COPYING Cat using Assignment Operator:" << std::endl;
	std::cout << "Cats constructing: ";
	std::cout << std::endl;
	Cat* original2 = new Cat();
	std::cout << std::endl;
	Cat* copy2 = new Cat();
	*copy2 = *original2;
	std::cout << std::endl;
	std::cout << "Delete the original: " << std::endl;
	delete original2;
	std::cout << std::endl;
	std::cout << "Copycat should still have a brain!: " << std::endl;
	copy2->getBrain()->sayFirstIdea();	
	std::cout << "Delete the copy: " << std::endl;
	delete copy2;
	std::cout << std::endl;
}

int main()
{
	constructDestructTest();
	deepCopiesTest();
}
