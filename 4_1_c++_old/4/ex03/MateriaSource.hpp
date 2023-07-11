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
		int	getNextEmptySlot();
		void learnMateria(AMateria* materiaToLearn);
		AMateria* createMateria(std::string const & type);
	private:
		AMateria* learnedMaterias[4];
		int nextEmptySlot;
};

#endif