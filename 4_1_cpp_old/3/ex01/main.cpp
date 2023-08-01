#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << std::endl;	
	std::cout << "-- Testing copy constructor:             " << std::endl;
	ScavTrap kimbap("Kimbap");
	ScavTrap kimbap2(kimbap);
	kimbap2.attack("Kimbap");
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "-- Testing assignment operator overload: " << std::endl;	
	ScavTrap filou("Filou");
	ScavTrap bonas("Bonas");	
	filou = bonas;
	filou.attack("Bonas");
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "-- Testing functionality:                " << std::endl;	
	ScavTrap mavis("Dave");
	ScavTrap olivia("Silvia");	
	mavis.attack("Silvia");
	olivia.takeDamage(47);	
	olivia.beRepaired(10);
	olivia.attack("Dave");
	mavis.takeDamage(69);
	mavis.guardGate();
	olivia.attack("Dave");
	mavis.takeDamage(32);
	mavis.beRepaired(2);	
	mavis.attack("Silvia");
	olivia.takeDamage(49);
	olivia.guardGate();
	olivia.beRepaired(2);
	olivia.attack("Dave");
	mavis.takeDamage(23);	
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
	return 0;
}