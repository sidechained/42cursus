#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called...";
	brain = new Brain();
	type = "Cat";
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called...";
}

Cat::Cat (const Cat &objToCopy)
{
	std::cout << "Cat copy-constructor called...";
	brain = new Brain(*objToCopy.brain);
	type = objToCopy.type;
}

Cat	&Cat::operator=(Cat &objToCopy)
{
	std::cout << "Cat assignment-operator called...";
	delete brain;
	brain = new Brain(*objToCopy.brain);
	type = objToCopy.type;
	return (*this);	
}

void	Cat::makeSound() const
{
	std::cout << "Cat says Meow!";
}

const	Brain* Cat::getBrain() const
{
	return brain;
}