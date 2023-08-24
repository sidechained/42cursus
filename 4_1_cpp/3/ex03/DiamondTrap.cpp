#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : FragTrap("nobody"), ScavTrap("nobody")
{	
	const char* name = "nobody";
	std::string suffix = "_clap_name";
	ClapTrap::name = name + suffix;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	ClapTrap::hitPoints = FragTrap::hitPoints;
	ClapTrap::energyPoints = ScavTrap::energyPoints;
	ClapTrap::attackDamage = FragTrap::attackDamage;	
	std::cout << "		DMNDTRAP CONSTRUCTING:	O my daze, " << name << " shines like a diamond with " << hitPoints << " hit points and " << energyPoints << " energy points and " << attackDamage << " attack damage!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string givenName) : FragTrap(givenName), ScavTrap(givenName)
{
	name = givenName;
	ClapTrap::name = name + "_clap_name";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	ClapTrap::hitPoints = FragTrap::hitPoints;
	ClapTrap::energyPoints = ScavTrap::energyPoints;
	ClapTrap::attackDamage = FragTrap::attackDamage;	
	std::cout << "		DMNDTRAP CONSTRUCTING:	O my daze, " << name << " shines like a diamond with " << hitPoints << " hit points and " << energyPoints << " energy points and " << attackDamage << " attack damage!" << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
	std::cout << "		DMNDTRAP CALLING SCAVTRAP ATTACK METHOD:" << std::endl;
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "		DMNDTRAP DESTRUCTING:	Pie and pie now, "  << name << " is no more!" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "		DMNDTRAP WHOAMI:	DiamondTrap name is " << name << ". Claptrap name is " << ClapTrap::name << std::endl;
}