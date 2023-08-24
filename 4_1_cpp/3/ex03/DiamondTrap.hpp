// Name (Parameter of constructor)
// Claptrap::Name (Parameter of constructor + "_clap_name")
// Hitpoints (Fragtrap)
// Energy points (Scavtrap)
// Attack damage (Fragtrap)
// attack (Scavtrap)

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap {
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string givenName);
		~DiamondTrap();
		void whoAmI();
		void attack(std::string const &target);
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;	
};

#endif