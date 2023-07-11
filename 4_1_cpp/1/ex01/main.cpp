#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int		main(void)
{
	Zombie *horde;
	int N;

	N = 5;
	horde = zombieHorde(N, "zombo");
	for(int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}