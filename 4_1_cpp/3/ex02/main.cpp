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
	FragTrap bevis("Bevis");
	FragTrap viola("Viola");	
	bevis.highFivesGuys();
	viola.highFivesGuys();
	bevis.attack("Viola");
	viola.takeDamage(69);	
	viola.beRepaired(10);
	viola.attack("Bevis");
	bevis.takeDamage(53);
	viola.attack("Bevis");
	bevis.takeDamage(42);
	bevis.beRepaired(2);	
	bevis.attack("Viola");
	viola.takeDamage(23);
	viola.beRepaired(2);
	viola.attack("Bevis");
	bevis.takeDamage(89);
	bevis.highFivesGuys();
	bevis.takeDamage(89);
}

int main()
{
	test_default_constructor();
	test_copy_constructor();
	test_assignment_op();
	test_functionality();
	return 0;
}
