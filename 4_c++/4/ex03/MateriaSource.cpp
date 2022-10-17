#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called" << std::endl;
		int i;
	i = 0;
	while(i <= 3)
	{
		learnedMaterias[i] = NULL;
		i++;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
}

int	MateriaSource::getNextEmptySlot()
{
	int i;
	i = 0;
	while(i <= 3)
	{
		if (learnedMaterias[i] == NULL)
			return (i);
		i++;
	}
	return(4);
}

// must copy the Materia passed as a parameter, and store it in memory to be cloned later
// as for Character, the Source can know at most 4 Materia, which are not necessarily unique
void MateriaSource::learnMateria(AMateria* materiaToLearn)
{
	std::cout << "MateriaSource learnMateria method called" << std::endl;
	nextEmptySlot = getNextEmptySlot();
	if (nextEmptySlot <= 3)
	{
		learnedMaterias[nextEmptySlot] = materiaToLearn;
		std::cout << "Materia " << materiaToLearn->getType() << " learned at position " << nextEmptySlot << std::endl;	
	}	
}

// will return a new Materia
// which will be a copy of the Materia (previously learned by the Source)
// which type equals the parameter
// Returns 0 if the type is unknown
AMateria* MateriaSource::createMateria(std::string const & type)
{
	std::cout << "MateriaSource createMateria method called" << std::endl;
	int i;
	i = 0;
	while(i <= 3)
	{
		if (learnedMaterias[i] != NULL)
		{
			if (learnedMaterias[i]->getType() == type)
				return (learnedMaterias[i]->clone());
		}	
		i++;
	}
	return(0);
}