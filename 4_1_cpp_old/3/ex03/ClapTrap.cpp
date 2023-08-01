#include "ClapTrap.hpp"

// default constructor to comply with orthodox canonical form
ClapTrap::ClapTrap()
	: name("nobody"), hitPoints(10), energyPoints(10), attackDamage(0)
{	
	std::cout << "CONSTRUCTING:	Joy to the world, " << name << " has been born with " << hitPoints << " hit points and " << energyPoints << " energy points!" << std::endl;
}

ClapTrap::ClapTrap(std::string givenName)
{
	this->name = givenName;
	this->hitPoints = 10;
	this->maxHitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	this->maxAttackDamage = 10;
	std::cout << "CLAPTRAP CONSTRUCTING:	Joy to the world, " << this->name << " has been born!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "CLAPTRAP DESTRUCTING:	Here lies " << this->name << ", now dust but never forgotten..." << std::endl;
}

// could also make use of assignment operator overload by doing "*this = copy" in main body instead;
ClapTrap::ClapTrap(const ClapTrap &copy)
	: name(copy.name), hitPoints(copy.hitPoints), energyPoints(copy.energyPoints), attackDamage(copy.attackDamage)
{
	std::cout << "Copy constructor called" << std::endl;
}

// assignation operator overload
ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "CLAPTRAP ASSIGNMENT OPERATOR OVERLOAD" << std::endl;
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;	
	return (*this);	
}

void ClapTrap::attack(std::string const &target)
{
	this->attackDamage = std::rand() % 10; // hardcoded, as replacing with this->attackDamage causes floating point error
	std::cout << "CLAPTRAP ATTACKING:	" << name << " attacks " << target << ", causing " << attackDamage << " point(s) of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "CLAPTRAP TAKING DAMAGE:	Of amount " << amount << ". ";
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
		std::cout << "CLAPTRAP REPAIRING:	" << this->name << " cannot be repaired. " << this->name << " is dead!!!" << std::endl;	
	}
	else {
		std::cout << "CLAPTRAP REPAIRING:	Of amount " << amount << ". ";
		if ((this->energyPoints - amount) < 0)
		{
			std::cout << "Sorry, you don't have enough energy points for that amount of repair." << std::endl;
		}
		else if ((this->hitPoints + amount) > this->maxHitPoints)
		{
			this->energyPoints = this->hitPoints + amount - this->maxHitPoints;
			this->hitPoints = this->maxHitPoints;
			std::cout << this->name << " fully repaired (" << this->hitPoints << ") and has " << this->energyPoints << " energy point(s) left." << std::endl;
		}
		else
		{
			this->energyPoints = this->energyPoints - amount;
			this->hitPoints = this->hitPoints + amount;		
			std::cout << this->name << " has used " << amount << " energy point(s), bringing their hit points up to " << this->hitPoints << "." << std::endl;
		}
	}
}

