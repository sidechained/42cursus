#include "ICharacter.hpp"

ICharacter::ICharacter(std::string const &name)
{
	std::cout << "ICharacter constructor called" << std::endl;
	this->_name = name;
	int i;
	i = 0;
	while(i < 4)
	{
		inventory[i] = NULL;
		i++;
	}
	currentMateria = 0;
}

ICharacter::~ICharacter()
{
	std::cout << "ICharacter destructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter &orig)
{
	std::cout << "ICharacter copy-constructor called" << std::endl;
	*this = orig;
}

ICharacter	&ICharacter::operator=(const ICharacter &orig)
{
	std::cout << "ICharacter assignment-operator called" << std::endl;
	this->_name = orig._name;
	//this->inventory = orig.inventory; // how to copy array? error says "not assignable"
	this->currentMateria = orig.currentMateria;
	return *this;
}

std::string const &ICharacter::getName() const
{
	return(this->_name);
}

void ICharacter::equip(AMateria* m)
{
	if (currentMateria != 3)
	{
		inventory[currentMateria] = m;
		currentMateria++;
	}
	else
		std::cout << "Inventory is full!" << std::endl;
}

void ICharacter::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
	{
		if (inventory[idx] != NULL)
			{
				std::cout << "Materia XXX unequipped" << std::endl;	
				inventory[idx] = NULL;
			}
		else
			std::cout << "Materia does not exist at that index" << std::endl;	
	}
}

void ICharacter::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
	{
		if (inventory[idx] != NULL)
				inventory[idx]->use(target); // Amateria::use ?!
		else
			std::cout << "Materia does not exist at that index" << std::endl;	
	}
}