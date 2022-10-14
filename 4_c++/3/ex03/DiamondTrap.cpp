#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string givenName) : FragTrap(givenName), ScavTrap(givenName)
{
	this->name = givenName;
	ClapTrap::name = givenName + "_clap_name";
	this->hitPoints = FragTrap::hitPoints;
	this->maxHitPoints = FragTrap::maxHitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	this->maxAttackDamage = FragTrap::maxAttackDamage;
	std::cout << "DIAMONDTRAP CONSTRUCTING:	Once again back is the incredible..." << this->name << std::endl;
	std::cout << "hitPoints: " << this->hitPoints;
	std::cout << ", maxHitPoints: " << this->maxHitPoints;
	std::cout << ", energyPoints: " << this->energyPoints;
	std::cout << ", attackDamage: " << this->attackDamage;
	std::cout << ", maxAttackDamage: " << this->attackDamage << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DIAMONDTRAP DESTRUCTING:	Pie and pie now, "  << this->name << " is no more!" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DIAMONDTRAP WHOAMI:	DiamondTrap name is " << this->name << ". Claptrap name is " << ClapTrap::name << std::endl;
}