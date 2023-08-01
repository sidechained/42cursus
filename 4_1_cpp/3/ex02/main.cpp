// From now on, each class you write MUST be in orthodox canonical form:
// At least one default constructor, a copy contructor, an assignation operator overload and a destructor.

// TODO: fix floating point error (rand modulo)
// TODO: force destroy objects (so that all destructions don't happen at end)...but tricky

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

void test_default_constructor()
{
	std::cout << std::endl;	
	std::cout << "-- Testing default constructor:" << std::endl;
	FragTrap nobody;
}

void test_copy_constructor()
{
	std::cout << std::endl;	
	std::cout << "-- Testing copy constructor:             " << std::endl;
	FragTrap kimbap("Kimbap");
	FragTrap kimbap2(kimbap);
	kimbap2.attack("Kimbap");
}

void test_assignment_op()
{
	std::cout << std::endl;
	std::cout << "-- Testing assignment operator overload: " << std::endl;	
	FragTrap filou("Filou");
	FragTrap bonas("Bonas");	
	filou = bonas;
	filou.attack("Bonas");
}

void test_functionality()
{
	std::cout << std::endl;	
	std::cout << "-- Testing functionality:                " << std::endl;	
	FragTrap mavis("Mavis");
	FragTrap olivia("Olivia");	
	mavis.highFivesGuys();
	olivia.highFivesGuys();
	mavis.attack("Silvia");
	olivia.takeDamage(69);	
	olivia.beRepaired(10);
	olivia.attack("Dave");
	mavis.takeDamage(53);
	olivia.attack("Dave");
	mavis.takeDamage(42);
	mavis.beRepaired(2);	
	mavis.attack("Silvia");
	olivia.takeDamage(23);
	olivia.beRepaired(2);
	olivia.attack("Dave");
	mavis.takeDamage(89);
	mavis.highFivesGuys();
	mavis.takeDamage(89);
}

int main()
{
	test_default_constructor();
	test_copy_constructor();
	test_assignment_op();
	test_functionality();
	return 0;
}
