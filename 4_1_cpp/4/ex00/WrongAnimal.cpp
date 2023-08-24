#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called..." << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called..." << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return(this->type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal says Gurgle!" << std::endl;
}