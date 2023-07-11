#include "Zombie.hpp"

// stack: return pointer to new Zombie object
Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
}