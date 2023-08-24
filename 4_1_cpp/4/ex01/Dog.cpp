#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called...";
	brain = new Brain();
	type = "Dog";
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called...";
}

Dog::Dog (const Dog &objToCopy)
{
	std::cout << "Cat copy-constructor called...";
	brain = new Brain(*objToCopy.brain);
	type = objToCopy.type;
}

Dog	&Dog::operator=(const Dog &objToCopy)
{
	std::cout << "Dog assignment-operator called...";
	brain = objToCopy.brain;
	type = objToCopy.type;	
	return (*this);	
}

void	Dog::makeSound() const
{
	std::cout << "Dog says Woof!";
}