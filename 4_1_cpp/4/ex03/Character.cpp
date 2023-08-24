#include "Character.hpp"

Character::Character(std::string const &name)
{
	// std::cout << "Character constructor called..." << std::endl;
	_name = name;
	for(int i = 0; i <= 3; i++)
		inventory[i] = NULL;
}

Character::~Character()
{
	// std::cout << "Character destructor called..." << std::endl;
	for(int i = 0; i <= 3; i++)
	{
		if(inventory[i] != NULL)
			delete inventory[i];
	}	
}

Character::Character(const Character &orig)
{
	// std::cout << "Character copy-constructor called..." << std::endl;
	*this = orig;
}

Character	&Character::operator=(const Character &orig)
{
	std::cout << "Character assignment-operator called..." << std::endl;
	_name = orig._name;
	// deep copy the inventory array
    for (int i = 0; i < 4; i++)
    {
        if (orig.inventory[i] != NULL)
		{
			delete inventory[i];
            inventory[i] = orig.inventory[i]->clone();
		}
        else
            inventory[i] = NULL;
    }
	return *this;
}

std::string const &Character::getName() const
{
	return _name;
}

int	Character::getNextEmptySlot()
{
	for(int i = 0; i <= 3; i++)
	{
		if (inventory[i] == NULL)
			return (i);
	}
	return -1;
}

void Character::equip(AMateria* m)
{
	int nextEmptySlot = getNextEmptySlot();
	// std::cout << "nes:" << nextEmptySlot << std::endl;
	if (nextEmptySlot != -1)
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