#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "MateriaSource constructor called..." << std::endl;
	for(int i = 0; i <= 3; i++)
		learnedMaterias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource destructor called..." << std::endl;
	for(int i = 0; i <= 3; i++)
		if (learnedMaterias[i] != NULL)
			delete learnedMaterias[i];
}

MateriaSource::MateriaSource(const MateriaSource &orig)
{
	// std::cout << "AMateria copy-constructor called..." << std::endl;
	*this = orig;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &orig)
{
	// std::cout << "AMateria assignment-operator called..." << std::endl;
    if (this != &orig)
    {
        for (int i = 0; i <= 3; i++)
        {
            delete learnedMaterias[i]; // Deallocate any dynamically allocated Materia objects
            learnedMaterias[i] = NULL;
            if (orig.learnedMaterias[i] != NULL)
                learnedMaterias[i] = orig.learnedMaterias[i]->clone(); // Assuming there's a clone() method in the Materia class
        }
    }
	return *this;
}

int	MateriaSource::getNextEmptySlot()
{
	for (int i = 0; i < 4; i++)
	{
		if (learnedMaterias[i] == NULL)
			return i;
	}
	return -1;
}

// must copy the Materia passed as a parameter, and store it in memory to be cloned later
// as for Character, the Source can know at most 4 Materia, which are not necessarily unique
void MateriaSource::learnMateria(AMateria* materiaToLearn)
{
	int nextEmptySlot;
	// std::cout << "MateriaSource learnMateria method called..." << std::endl;
	nextEmptySlot = getNextEmptySlot();
	if (nextEmptySlot != -1)
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
	// std::cout << "MateriaSource createMateria method called..." << std::endl;
	for (int i = 0; i <= 3; i++)
	{
		if (learnedMaterias[i] != NULL)
		{
			if (learnedMaterias[i]->getType() == type)
				return (learnedMaterias[i]->clone());
		}
	}
	return 0;
}