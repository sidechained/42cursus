#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called..." << std::endl;
	this->brain = new Brain();
	type = "Dog";
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called..." << std::endl;
}

Dog::Dog (const Dog &objToCopy)
{
	std::cout << "Dog copy-constructor called..." << std::endl;
	*this = objToCopy;
}

Dog	&Dog::operator=(const Dog &objToCopy)
{
	std::cout << "Dog assignment-operator called..." << std::endl;
	this->brain = objToCopy.brain;
	this->type = objToCopy.type;	
	return (*this);	
}

void	Dog::makeSound() const
{
	std::cout << "Dog says Woof!" << std::endl;
}