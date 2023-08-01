#include "ScavTrap.hpp"

// default constructor to comply with orthodox canonical form
ScavTrap::ScavTrap()
{	
}

// ": ClapTrap(givenName)" below ensures correct constructor is called (as opposed to default constructor, which we don't have)
ScavTrap::ScavTrap(std::string givenName)
	: ClapTrap(givenName)
{
	std::cout << "	SCAVTRAP CONSTRUCTING:	Oh rejoice fellow countrymen, " << name << " has entered into the world!" << std::endl;
	std::cout << "	" << name;
	std::cout << ": [hitPoints: " << hitPoints;
	std::cout << ", energyPoints: " << energyPoints;
	std::cout << ", attackDamage: " << attackDamage;
	std::cout << "]" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "	SCAVTRAP DESTRUCTING:	So long "  << name << " and thanks for all the fish!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "	SCAVTRAP IN GATEKEEPER MODE" << std::endl;
}