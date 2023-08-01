// key point: in order to override a function, the base function should be declared as 'virtual'
// the destructor of the base class should also be declared virtual
// in WrongAnimal.hpp I removed both the above 'virtuals' (makeSound + destructor)
// in WrongCat, nothing has changed apart from class/type name

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void standardTests()
{
	std::cout << std::endl << "First the standard tests:"	;
	std::cout << std::endl << "-Creation of an animal..." << std::endl;
	const Animal* meta = new Animal();
	std::cout << std::endl << "-Creation of a dog..." << std::endl;
	const Animal* d = new Dog();
	std::cout << std::endl << "-Creation of a cat..." << std::endl;
	const Animal* c = new Cat();
	std::cout << std::endl << "-Get type of animal..." << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << std::endl << "-Get type of dog..." << std::endl;
	std::cout << d->getType() << " " << std::endl;
	std::cout << std::endl << "-Get type of cat..." << std::endl;	
	std::cout << c->getType() << " " << std::endl;
	std::cout << std::endl << "-Animal make sound..." << std::endl;
	meta->makeSound();
	std::cout << std::endl << "-Dog make sound..." << std::endl;
	d->makeSound();
	std::cout << std::endl << "-Cat make sound..." << std::endl;
	c->makeSound();
	std::cout << std::endl << "-Destruction of animal..." << std::endl;
	delete meta;
	std::cout << std::endl << "-Destruction of cat..." << std::endl;
	delete c;
	std::cout << std::endl << "-Destruction of dog..." << std::endl;
	delete d;
}

void wrongCatTests()
{
	std::cout << std::endl << "Now for the WrongCat/WrongAnimal tests:";
	std::cout << std::endl << "-Creation of a WrongCat..." << std::endl;
	const WrongAnimal* k = new WrongCat();
	std::cout << std::endl << "-Get type of WrongCat..." << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << std::endl << "-WrongCat make sound..." << std::endl;
	k->makeSound();
	std::cout << std::endl << "-Destruction of WrongCat..." << std::endl;
	delete k;
}

int main()
{
	standardTests();
	wrongCatTests();
	return 0;
}