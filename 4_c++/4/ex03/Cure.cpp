#include "Cure.hpp"

Cure::Cure() : AMateria("cure") // explicit call to AMateria constructor (as AMateria has no default constructor)
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure &orig) : AMateria(orig) // explicit call to AMateria constructor (as AMateria has no default constructor)
{
	std::cout << "Cure copy-constructor called" << std::endl;
	*this = orig;
}

Cure	&Cure::operator=(const Cure &orig)
{
	std::cout << "Cure assignment-operator called" << std::endl;
	this->_type = orig._type;
	return *this;
}

AMateria	*Cure::clone() const
{
	std::cout << "Cure clone method called" << std::endl;
	// return a new instance of the real Materia's type
	return (new Cure(*this)); // uses copy constructor?
}

// virtual void use(ICharacter& target) // name of character given, not object instance
// {
// 	std::cout << "* heals " << target << "'s wounds *" << std::endl;
// }