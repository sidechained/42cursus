#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

// use of virtual here avoids 'diamond inheritence' and ensures that only one copy of the base class is shared among multiple derived classes in the inheritance hierarchy
class FragTrap: virtual public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string givenName);
		~FragTrap();
		void highFivesGuys(void);
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;	
};

#endif