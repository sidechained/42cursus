#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap(std::string givenName);
		~FragTrap(void);
		void highFivesGuys(void);
};

#endif