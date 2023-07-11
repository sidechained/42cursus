#include "Zombie.hpp"

// heap: the destructor is called (and presumably memory freed) on reaching function end
void	randomChump(std::string name)
{
	Zombie	z = Zombie(name);
	z.announce();
}