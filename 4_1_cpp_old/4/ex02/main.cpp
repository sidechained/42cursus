#include "AnimalP.hpp"
#include "Cat.hpp"

// key point: to be made abstract, Animal class has been given one 'pure virtual' function
// this is done by adding '= 0' at end of function declaration in header
// makeSound function in Animal class is now pointless, so I also removed it
int main()
{
	// this should cause: "error: allocating an object of abstract class type 'Animal'"
	// const Animal* animal = new Animal();
	// comment out the above line, and the following code should still work:
	const Cat* cat = new Cat();
	cat->makeSound();
}