#include "Ice.hpp"

Ice::Ice() : AMateria("ice") // explicit call to AMateria constructor (as AMateria has no default constructor)
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice &orig) : AMateria(orig) // explicit call to AMateria constructor (as AMateria has no default constructor)
{
	std::cout << "Ice copy-constructor called" << std::endl;
	*this = orig;
}

Ice	&Ice::operator=(const Ice &orig)
{
	std::cout << "Ice assignment-operator called" << std::endl;
	this->_type = orig._type;
	return *this;
}

AMateria	*Ice::clone() const
{
	std::cout << "Ice clone method called" << std::endl;
	// return a new instance of the real Materia's type
	return (new Ice(*this)); // uses copy constructor?
}

// virtual void use(ICharacter& target) // name of character given, not object instance
// {
// 	std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
// }