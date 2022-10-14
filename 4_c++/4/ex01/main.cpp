#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// TODO: deep copies
// TODO: brain should have 100 ideas

void constructDestructTest()
{
	const Animal* animalArray[6];
	int i;

	i = 0;
	while(i < 3)
	{
		std::cout << i << ":" << std::endl;
		animalArray[i] = new Dog();
		i++;
	}
	while(i < 6)
	{
		std::cout << i << ":" << std::endl;
		animalArray[i] = new Cat();
		i++;
	}

	i = 0;
	while(i < 6)
	{
		std::cout << i << ":" << std::endl;
		animalArray[i]->makeSound();
		i++;
	}

	i = 0;
	while(i < 6)
	{
		std::cout << i << ":" << std::endl;		
		delete animalArray[i];
		i++;
	}
}

void deepCopiesTest()
{
	// How can we tell this has been done correctly?
	// Should we also test with Dog and Animal?

	// TESTING COPY CONSTRUCTOR
	std::cout << "COPYING Cat into Cat using Copy Constructor:" << std::endl;
	const Cat* original1 = new Cat();
	std::cout << "ORIGINAL:" << std::endl;
	original1->makeSound();
	original1->brain->sayFirstIdea();
	original1->getType();
	std::cout << "COPY:" << std::endl;	
	const Cat* copy1(original1);	
	original1 = copy1;
	original1->makeSound();
	original1->brain->sayFirstIdea();
	original1->getType();	
	std::cout << std::endl;

	// TESTING ASSIGNMENT OPERATOR
	// our test of 'deep' is, when Dog is copied into Cat, is getType() correctly printed?
	std::cout << "COPYING Cat into Cat using Assignment Operator:" << std::endl;		
	const Cat* original2 = new Cat();
	const Cat* copy2 = new Cat();
	std::cout << "ORIGINAL:" << std::endl;	
	original2->makeSound();
	original2->brain->sayFirstIdea();
	original2->getType();
	std::cout << "COPY:" << std::endl;	
	original2 = copy2;
	original2->makeSound();
	original2->brain->sayFirstIdea();
	original2->getType();
	std::cout << std::endl;
}

int main()
{
	const Animal* animal = new Animal();
	animal->getType();
	//constructDestructTest();
	//deepCopiesTest();
}