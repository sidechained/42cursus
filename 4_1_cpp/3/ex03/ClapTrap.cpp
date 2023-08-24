#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("nobody"), hitPoints(10), energyPoints(10), attackDamage(0)
{	
	std::cout << "CLAPTRAP CONSTRUCTING:	Joy to the world, " << name << " has been born with " << hitPoints << " hit points and " << energyPoints << " energy points and " << attackDamage << " attack damage!" << std::endl;
}

ClapTrap::ClapTrap(std::string givenName)
	: name(givenName), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "CLAPTRAP CONSTRUCTING:	Joy to the world, " << name << " has been born with " << hitPoints << " hit points and " << energyPoints << " energy points and " << attackDamage << " attack damage!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "CLAPTRAP DESTRUCTING:	Here lies " << name << ", now dust but never forgotten..." << std::endl;
}

// could also make use of assignment operator overload by doing "*this = copy" in main body instead;
ClapTrap::ClapTrap(const ClapTrap &copy)
	: name(copy.name), hitPoints(copy.hitPoints), energyPoints(copy.energyPoints), attackDamage(copy.attackDamage)
{
	std::cout << "CLAPTRAP COPY CONSTRUCTOR CALLED" << std::endl;
}

// assignation operator overload
ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "CLAPTRAP ASSIGNMENT OPERATOR OVERLOAD" << std::endl;
	name = copy.name;
	hitPoints = copy.hitPoints;
	energyPoints = copy.energyPoints;
	attackDamage = copy.attackDamage;
	return (*this);	
}

void ClapTrap::attack(std::string const &target)
{
	if (energyPoints <= 0)
	{
		std::cout << "CLAPTRAP ATTACKING:	" << name << " doesn't have enough energy points to make the attack!" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "CLAPTRAP ATTACKING:	" << name << " attacks " << target << " and now has " << energyPoints << " energy points remaining." << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "CLAPTRAP TAKING DAMAGE:	" << name << " is already dead...let them R.I.P!" << std::endl;
		return ;
	}
	std::cout << "CLAPTRAP TAKING DAMAGE:	" << name << " takes an attack damage of " << amount << ". ";
	if (hitPoints < amount)
	{
		hitPoints = 0;
		std::cout << "Oh dear they have " << hitPoints << " hit point(s) remaining and die." << std::endl;
	}
	else
	{
		hitPoints = hitPoints - amount;
		std::cout << "Luckily they have " << hitPoints << " hit point(s) remaining." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "CLAPTRAP REPAIRING:	" << name << " cannot be repaired. " << name << " is dead!!!" << std::endl;
		return ;
	}
	if (energyPoints < 1)
	{
		std::cout << "CLAPTRAP REPAIRING:	Sorry, you don't have enough energy points." << std::endl;
		return ;
	}
	energyPoints--;
	hitPoints = hitPoints + amount;	
	std::cout << "CLAPTRAP REPAIRING:	" << name << " has been repaired by " << amount << " hitpoints, to a new total of " << hitPoints << " hitpoints, and has " << energyPoints << " energy point(s) remaining." << std::endl;
}



