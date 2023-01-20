#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	this->brain = new Brain();
	type = "Cat";
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat (const Cat &objToCopy)
{
	std::cout << "Cat copy-constructor called" << std::endl;
	*this = objToCopy;
}

Cat	&Cat::operator=(const Cat &objToCopy)
{
	std::cout << "Cat assignment-operator called" << std::endl;
	this->brain = objToCopy.brain;
	this->type = objToCopy.type;	
	return (*this);	
}

void	Cat::makeSound() const
{
	std::cout << "Cat says Meow!" << std::endl;
}