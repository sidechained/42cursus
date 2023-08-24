#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{	
	name = "nobody";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "	SCAVTRAP CONSTRUCTING:	Oh rejoice fellow countrymen, " << name << " has entered into the world with " << hitPoints << " hit points and " << energyPoints << " energy points and " << attackDamage << " attack damage!" << std::endl;
}

ScavTrap::ScavTrap(std::string givenName)
{
	name = givenName;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "	SCAVTRAP CONSTRUCTING:	Oh rejoice fellow countrymen, " << name << " has entered into the world with " << hitPoints << " hit points and " << energyPoints << " energy points and " << attackDamage << " attack damage!" << std::endl;
}

// technically scavtrap should have copy constructor and assignment operator overload member functions but these are inherited from claptrap

ScavTrap::~ScavTrap(void)
{
	std::cout << "	SCAVTRAP DESTRUCTING:	So long "  << this->name << " and thanks for all the fish!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "	SCAVTRAP IN GATEKEEPER MODE" << std::endl;
}