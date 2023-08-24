#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
	// std::cout << "AMateria constructor called..." << std::endl;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria destructor called..." << std::endl;
}

// no need for deep copying as class doesn't contain pointers or dynamically allocated resources
AMateria::AMateria(const AMateria &orig)
{
	// std::cout << "AMateria copy-constructor called..." << std::endl;
	*this = orig;
}

AMateria	&AMateria::operator=(const AMateria &orig)
{
	// std::cout << "AMateria assignment-operator called..." << std::endl;
	_type = orig._type;
	return *this;
}

std::string const &AMateria::getType() const
{
	// std::cout << "AMateria getType method called..." << std::endl;
	return(this->_type);
}
