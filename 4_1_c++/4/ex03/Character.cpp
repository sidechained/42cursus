#include "Character.hpp"

Character::Character(std::string const &name)
{
	std::cout << "Character constructor called" << std::endl;
	this->_name = name;
	int i;
	i = 0;
	while(i <= 3)
	{
		inventory[i] = NULL;
		i++;
	}
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	int i;
	i = 0;
	while(i <= 3)
	{
		if(inventory[i] != NULL)
			delete inventory[i];
		i++;
	}	
}

Character::Character(const Character &orig)
{
	std::cout << "Character copy-constructor called" << std::endl;
	*this = orig;
}

// Character	&Character::operator=(const Character &orig)
// {
// 	std::cout << "Character assignment-operator called" << std::endl;
// 	this->_name = orig._name;
// 	//this->inventory = orig.inventory; // how to copy array? error says "not assignable"
// 	this->nextEmptySlot = orig.nextEmptySlot;
// 	return *this;
// }

std::string const &Character::getName() const
{
	return(this->_name);
}

int	Character::getNextEmptySlot()
{
	int i;
	i = 0;
	while(i <= 3)
	{
		if (inventory[i] == NULL)
			return (i);
		i++;
	}
	return(4);
}

void Character::equip(AMateria* m)
{
	nextEmptySlot = getNextEmptySlot();
	if (nextEmptySlot <= 3)
	{
		inventory[nextEmptySlot] = m;
		std::cout << "Materia " << m->getType() << " equipped at position " << nextEmptySlot << " in inventory" << std::endl;	
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
	{
		if (inventory[idx] != NULL)
			{
				std::cout << "Materia " << inventory[idx]->getType() << " unequipped at position " << idx << " in inventory" << std::endl;	
				inventory[idx] = NULL;
			}
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
	{
		if (inventory[idx] != NULL)
			inventory[idx]->use(target);
	}
}