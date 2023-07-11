#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// Key Takeaway:
// Both approaches allow the humans to store a reference to the Weapon object without making a copy of it.
// HumanA takes the Weapon in its constructor and stores it as a reference (&)
// HumanB takes the Weapon in its setWeapon method and stores it as a pointer (*)
// If you want a class to have its own ownership and control over a Weapon object, a reference is typically a good choice.
// If you want a class to refer to or share a Weapon object without ownership, a pointer is usually more appropriate.

int		main(void)
{
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}