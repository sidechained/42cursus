#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cmath>

class ClapTrap {
	private:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string givenName);
		~ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap	&operator=(const ClapTrap &copy);		
		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif