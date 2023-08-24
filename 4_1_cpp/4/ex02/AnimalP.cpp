#include "AnimalP.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called..." << std::endl;
	type = "Animal";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called..." << std::endl;
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