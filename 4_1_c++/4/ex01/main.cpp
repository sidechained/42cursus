#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void constructDestructTest()
{
	std::cout << "--- Testing Construction and Destruction:" << std::endl;

	const Animal* animalArray[BRAINSIZE];
	int i;

	i = 0;
	while(i < BRAINSIZE/2)
	{
		std::cout << i << ":" << std::endl;
		animalArray[i] = new Dog();
		i++;
	}
	while(i < BRAINSIZE)
	{
		std::cout << i << ":" << std::endl;
		animalArray[i] = new Cat();
		i++;
	}

	i = 0;
	while(i < BRAINSIZE)
	{
		std::cout << i << ":" << std::endl;
		animalArray[i]->makeSound();
		i++;
	}

	i = 0;
	while(i < BRAINSIZE)
	{
		std::cout << i << ":" << std::endl;		
		delete animalArray[i];
		i++;
	}
	std::cout << std::endl;
}

// Tests if copying Cat also copies state of base class Animal, by:
// - creating instance of Cat and copying it (either by copy constructor or assignment operator)
// - calling getType() method (which belongs only to Animal class) to see if it returns 'Cat'
// - also calling other methods that belong to cat, for confirmation
void deepCopiesTest()
{
	std::cout << "--- Testing if copies are 'deep':" << std::endl;

	// TESTING COPY CONSTRUCTOR
	std::cout << "COPYING Cat using Copy Constructor:" << std::endl;
	const Cat* original1 = new Cat();
	const Cat* copy1(original1);	
	std::cout << copy1->getType() << std::endl;	
	copy1->makeSound();
	copy1->brain->sayFirstIdea();
	std::cout << std::endl;

	// TESTING ASSIGNMENT OPERATOR
	std::cout << "COPYING Cat using Assignment Operator:" << std::endl;		
	const Cat* original2 = new Cat();
	const Cat* copy2 = new Cat();
	copy2 = original2;
	std::cout << copy2->getType() << std::endl;	
	copy2->makeSound();
	copy2->brain->sayFirstIdea();
	std::cout << std::endl;
}

int main()
{
	constructDestructTest();
	deepCopiesTest();
}