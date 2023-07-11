#include "FragTrap.hpp"

// ": ClapTrap(givenName)" below ensures correct constructor is called (as opposed to default constructor, which we don't have)
FragTrap::FragTrap(std::string givenName) : ClapTrap(givenName)
{
	this->name = givenName;
	this->hitPoints = 100;
	this->maxHitPoints = this->hitPoints;
	this->energyPoints = 100;
	this->attackDamage = 30;
	this->maxAttackDamage = this->attackDamage;
	std::cout << "FRAGTRAP CONSTRUCTING:	Oh rejoice fellow countrymen, " << this->name << " has entered into the world!" << std::endl;
	std::cout << "hitPoints: " << this->hitPoints;
	std::cout << ", maxHitPoints: " << this->maxHitPoints;
	std::cout << ", energyPoints: " << this->energyPoints;
	std::cout << ", attackDamage: " << this->attackDamage;
	std::cout << ", maxAttackDamage: " << this->attackDamage << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FRAGTRAP DESTRUCTING:	So long "  << this->name << " and thanks for all the fish!" << std::endl;
}

void FragTrap::attack(std::string const &target)
{
	this->attackDamage = std::rand() % 20; // hardcoded, as replacing with this->attackDamage causes floating point error
	std::cout << "FRAGTRAP ATTACKING:	" << name << " savages " << target << ", inflicting " << attackDamage << " point(s) of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FRAGTRAP KINDLY REQUESTS POSITIVE HIGH FIVES!!!" << std::endl;
}