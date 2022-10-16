// key point: in order to override a function, the base function should be declared as 'virtual'
// the destructor of the base class should also be declared virtual
// in WrongAnimal.hpp I removed both the above 'virtuals' (makeSound + destructor)
// in WrongCat, nothing has changed apart from class/type name

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void standardTests()
{
	std::cout << std::endl << "First the standard tests:" << std::endl;
	const Animal* meta = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	std::cout << d->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	d->makeSound();
	c->makeSound();
	meta->makeSound();
	delete d;
	delete c;
	delete meta;
}

void wrongCatTests()
{
	std::cout << std::endl << "Now for the WrongCat/WrongAnimal tests:" << std::endl;
	const WrongAnimal* k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	delete k;
}

int main()
{
	standardTests();
	wrongCatTests();
	return (0);
}