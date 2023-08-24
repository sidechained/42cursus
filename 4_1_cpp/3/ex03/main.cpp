// used the -Wno-shadow flag with Makefile to suppress warning messages from using the same 'name' variable in both ClapTrap and Diamondtrap. In general this is not recommended
// Variable shadowing occurs when a new variable declared within a nested scope (such as a function or block) has the same name as a variable declared in an outer scope. This can lead to confusion and bugs, as the inner variable can "shadow" the outer one, making the outer variable inaccessible within the nested scope.

// Attributes for DiamondTrap instances should be:
// Hit points (FragTrap) 100
// Energy points (ScavTrap) 50
// Attack damage (FragTrap) 30

// solved: ClapTrap, ScavTrap, FragTrap and DiamondTrap all need their own independent variables for hit points, energy points and attack damage, otherwise they get overwritten during construction i.e. ScavTrap overwrites FragTrap

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

void test_copy_constructor()
{
	std::cout << std::endl;	
	std::cout << "-- Testing copy constructor:             " << std::endl;
	DiamondTrap kimbap("Kimbap");
	DiamondTrap kimbap2(kimbap);
	kimbap2.attack("Kimbap");
}

void test_assignment_op()
{
	std::cout << std::endl;
	std::cout << "-- Testing assignment operator overload: " << std::endl;	
	DiamondTrap filou("Filou");
	DiamondTrap bonas("Bonas");	
	filou = bonas;
	filou.attack("Bonas");
}

void test_functionality()
{
	std::cout << std::endl;
	std::cout << "-- Testing functionality:                " << std::endl;	
	DiamondTrap vikram("Vikram");
	DiamondTrap alivio("Alivio");
	vikram.whoAmI();
	alivio.whoAmI();
	vikram.attack("Alivio");
	alivio.takeDamage(30);	
	alivio.beRepaired(10);
	alivio.attack("Vikram");
	vikram.takeDamage(30);
	alivio.attack("Vikram");
	vikram.takeDamage(30);
	vikram.beRepaired(2);	
	vikram.attack("Alivio");
	alivio.takeDamage(30);
	alivio.beRepaired(2);
	alivio.attack("Vikram");
	vikram.takeDamage(30);
}

int main()
{
	test_copy_constructor();
	test_assignment_op();
	test_functionality();
	return 0;
}
