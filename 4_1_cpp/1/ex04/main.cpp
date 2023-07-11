#include "SedIsDead.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "ERROR: Wrong number of arguments (needs <input filename> <string to find> <string to replace with>)" << std::endl;
		return(0);
	}
	SedIsDead(argv[1], argv[2], argv[3]);
}
