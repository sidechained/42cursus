// key point: in order to override a function, the base function should be declared as 'virtual'
// the destructor of the base class should also be declared virtual
// in WrongAnimal.hpp I removed both the above 'virtuals'
// in WrongCat, nothing has changed apart from class/type name

// should all of these includes be here?
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

void standardTests()
{
	std::cout << std::endl << "First the standard tests:" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
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