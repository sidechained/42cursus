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
	std::cout << "	DIAMONDTRAP CONSTRUCTING:	Once again back is the incredible..." << name << "... with " << hitPoints << " hit points and " << energyPoints << " energy points!" << std::endl;	
}

DiamondTrap::DiamondTrap(std::string givenName) : FragTrap(givenName), ScavTrap(givenName)
{
	name = givenName;
	ClapTrap::name = name + "_clap_name";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "	DIAMONDTRAP CONSTRUCTING:	Once again back is the incredible..." << name << "... with " << hitPoints << " hit points and " << energyPoints << " energy points!" << std::endl;	
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DIAMONDTRAP DESTRUCTING:	Pie and pie now, "  << name << " is no more!" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DIAMONDTRAP WHOAMI:	DiamondTrap name is " << name << ". Claptrap name is " << ClapTrap::name << std::endl;
}