// Name (Parameter of constructor)
// Claptrap::Name (Parameter of constructor + "_clap_name")
// Hitpoints (Fragtrap)
// Energy points (Scavtrap)
// Attack damage (Fragtrap)
// attack (Scavtrap)

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream> // cout
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
};

#endif