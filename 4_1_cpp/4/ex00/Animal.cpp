#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called..." << std::endl;
	type = "Animal";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called..." << std::endl;
}

std::string	Animal::getType() const
{
	return(this->type);
}

void	Animal::makeSound() const
{
	std::cout << "Animal says Gurgle!" << std::endl;
}