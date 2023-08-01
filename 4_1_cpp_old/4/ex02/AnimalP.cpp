#include "AnimalP.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	type = "Animal";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType() const
{
	return(this->type);
}