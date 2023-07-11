#include "HumanB.hpp"

// constructor uses initialiser list to initialise _name and _weapon
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with his " << _weapon->getType() << std::endl;
}