// TODO: fix floating point error (rand modulo)
// TODO: force destroy objects (so that all destructions don't happen at end)...but tricky
// TODO: DiamondTrap, FragTrap and ScavTrap should have their own copy constructors and operator overloads as these are not inherited - see here:
// https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm

// address: Do you know the -Wshadow and -Wno-shadow compiler flags?

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

void test_copy_constructor()
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
}

void test_assignment_op()
{
	std::cout << "-- Testing assignment operator overload: " << std::endl;	
	FragTrap filou("Filou");
	FragTrap bonas("Bonas");	
	filou = bonas;
	filou.attack("Bonas");
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << std::endl;
}

void test_functionality()
{
	std::cout << "-- Testing functionality:                " << std::endl;	
	FragTrap mavis("Dave");
	FragTrap olivia("Silvia");	
	mavis.attack("Silvia");
	olivia.takeDamage(20);	
	olivia.beRepaired(10);
	olivia.attack("Dave");
	mavis.takeDamage(20);
	olivia.attack("Dave");
	mavis.takeDamage(20);
	mavis.beRepaired(2);	
	mavis.attack("Silvia");
	olivia.takeDamage(20);
	olivia.beRepaired(2);
	olivia.attack("Dave");
	mavis.takeDamage(20);
	mavis.highFivesGuys();
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "* * * DESTRUCTIONS:                " << std::endl;	
}

int main()
{
	test_copy_constructor();
	test_assignment_op();
	test_functionality();
	return 0;
}
