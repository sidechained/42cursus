#include "ScavTrap.hpp"

// ": ClapTrap(givenName)" below ensures correct constructor is called (as opposed to default constructor, which we don't have)
ScavTrap::ScavTrap(std::string givenName) : ClapTrap(givenName)
{
	this->name = givenName;
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	maxAttackDamage = 20;
	std::cout << "SCAVTRAP CONSTRUCTING:	Oh rejoice fellow countrymen, " << this->name << " has entered into the world!" << std::endl;
	std::cout << "hitPoints: " << this->hitPoints << std::endl;
	std::cout << "maxHitPoints: " << this->maxHitPoints << std::endl;
	std::cout << "energyPoints: " << this->energyPoints << std::endl;
	std::cout << "attackDamage: " << this->attackDamage << std::endl;
	std::cout << "maxAttackDamage: " << this->attackDamage << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "SCAVTRAP DESTRUCTING:	So long "  << this->name << " and thanks for all the fish!" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	this->attackDamage = std::rand() % 20; // hardcoded, as replacing with this->attackDamage causes floating point error
	std::cout << "SCAVTRAP ATTACKING:	" << name << " savages " << target << ", inflicting " << attackDamage << " point(s) of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "SCAVTRAP IN GATEKEEPER MODE" << std::endl;
}