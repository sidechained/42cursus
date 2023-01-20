// From now on, each class you write MUST be in orthodox canonical form:
// At least one default constructor, a copy contructor, an assignation operator overload and a destructor.

// TODO: fix floating point error (rand modulo)
// TODO: force destroy objects (so that all destructions don't happen at end)...but tricky
// TODO: DiamondTrap, FragTrap and ScavTrap should have their own copy constructors and operator overloads as these are not inherited - see here:
https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << std::endl;
	std::cout << "* * * NEW FRAGTRAP TESTS (only):                " << std::endl;	
	std::cout << std::endl;	
	std::cout << "-- Testing copy constructor:             " << std::endl;
	FragTrap kimbap("Kimbap");
	FragTrap kimbap2(kimbap);
	kimbap2.attack("Kimbap");
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "-- Testing assignment operator overload: " << std::endl;	
	FragTrap filou("Filou");
	FragTrap bonas("Bonas");	
	filou = bonas;
	filou.attack("Bonas");
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "-- Testing functionality:                " << std::endl;	
	FragTrap mavis("Dave");
	FragTrap olivia("Silvia");	
	mavis.attack("Silvia");
	olivia.takeDamage(mavis.getAttackDamage());	
	olivia.beRepaired(10);
	olivia.attack("Dave");
	mavis.takeDamage(olivia.getAttackDamage());
	olivia.attack("Dave");
	mavis.takeDamage(olivia.getAttackDamage());
	mavis.beRepaired(2);	
	mavis.attack("Silvia");
	olivia.takeDamage(mavis.getAttackDamage());
	olivia.beRepaired(2);
	olivia.attack("Dave");
	mavis.takeDamage(mavis.getAttackDamage());
	mavis.highFivesGuys();
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "* * * DESTRUCTIONS:                " << std::endl;	
	return (0);
}