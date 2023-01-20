#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string givenName)
{
	this->name = givenName;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;	
	std::cout << "CONSTRUCTING:	Joy to the world, " << this->name << " has been born!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "DESTRUCTING:	Here lies " << this->name << ", now dust but never forgotten..." << std::endl;
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

// assignation operator overload
ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Assignation operator called" << std::endl;
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;	
	return (*this);	
}

void ClapTrap::attack(std::string const &target)
{
	this->attackDamage = std::rand() % 10;
	std::cout << "ATTACKING:	" << name << " attacks " << target << ", causing " << attackDamage << " point(s) of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "TAKING DAMAGE:	Of amount " << amount << ". ";
	if (this->hitPoints < amount)
	{
		this->hitPoints = 0;
		std::cout << "Oh dear, " << this->name << " has " << this->hitPoints << " hit point(s) remaining and has died an untimely death." << std::endl;
	}
	else
	{
		this->hitPoints = this->hitPoints - amount;
		std::cout << "Luckily, " << this->name << " has " << this->hitPoints << " hit point(s) remaining." << std::endl;
	}

}

unsigned int ClapTrap::getAttackDamage()
{
	return(this->attackDamage);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "REPAIRING:	" << this->name << " cannot be repaired. " << this->name << " is dead!!!" << std::endl;	
	}
	else {
		std::cout << "REPAIRING:	Of amount " << amount << ". ";
		if ((this->energyPoints - amount) < 0)
		{
			std::cout << "Sorry, you don't have enough energy points for that amount of repair." << std::endl;
		}
		else if ((this->hitPoints + amount) > 10)
		{
			this->energyPoints = this->hitPoints + amount - 10;
			this->hitPoints = 10;
			std::cout << this->name << " has been fully repaired (" << this->hitPoints << ") and has " << this->energyPoints << " energy point(s) remaining." << std::endl;
		}
		else
		{
			this->energyPoints = this->energyPoints - amount;
			this->hitPoints = this->hitPoints + amount;		
			std::cout << this->name << " has used " << amount << " energy point(s), bringing their hit points up to " << this->hitPoints << "." << std::endl;
		}
	}
}

