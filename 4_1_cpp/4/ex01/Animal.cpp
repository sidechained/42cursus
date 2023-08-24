#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called...";
	type = "Animal";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called...";
}

Animal::Animal (const Animal &objToCopy)
{
	std::cout << "Animal copy-constructor called...";
	*this = objToCopy;
}

Animal	&Animal::operator=(const Animal &objToCopy)
{
	std::cout << "Animal assignment-operator called...";
	type = objToCopy.type;	
	return (*this);	
}

std::string	Animal::getType() const
{
	return(this->type);
}

void	Animal::makeSound() const
{
	std::cout << "Animal says Gurgle!" << std::endl;
}