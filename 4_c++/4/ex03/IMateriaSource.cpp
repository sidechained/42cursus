#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
	std::cout << "IMateriaSource constructor called" << std::endl;
}

IMateriaSource::~IMateriaSource()
{
	std::cout << "IMateriaSource destructor called" << std::endl;
}

virtual void IMateriaSource::learnMateria(AMateria*)
{
	std::cout << "IMateriaSource learnMateria method called" << std::endl;
	// must copy the Materia passed as a parameter, and store it in memory to be cloned later
	// as for Character, the Source can know at most 4 Materia, which are not necessarily unique
}

virtual AMateria* IMateriaSource::createMateria(std::string const & type)
{
	std::cout << "IMateriaSource createMateria method called" << std::endl;
	// will return a new Materia
	// which will be a copy of the Materia (previously learned by the Source)
	// which type equals the parameter
	// Returns 0 if the type is unknown
}