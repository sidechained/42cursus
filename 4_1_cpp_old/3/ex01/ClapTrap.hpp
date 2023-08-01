#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cmath>
class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(std::string givenName);
		~ClapTrap(void);
		ClapTrap(const ClapTrap &copy);
		ClapTrap	&operator=(const ClapTrap &copy);		
		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	protected:
		ClapTrap();
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
};

#endif