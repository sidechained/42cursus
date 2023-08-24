#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class AMateria; // this has to be here otherwise "error: unknown type name 'AMateria'""

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &orig);
		MateriaSource &operator=(const MateriaSource &orig);		
		int	getNextEmptySlot();
		void learnMateria(AMateria* materiaToLearn);
		AMateria* createMateria(std::string const & type);
	protected:
		AMateria* learnedMaterias[4];
		
};

#endif