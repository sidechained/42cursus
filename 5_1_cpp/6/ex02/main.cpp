#include "Base.hpp"

#define MAX_TRIES 5

int main()
{
	Base::setSeed();
	std::cout << std::endl;
	std::cout << "TESTING: Identifying from pointer" << std::endl;
	for(int i = 0; i < MAX_TRIES; i++)
	{
		std::cout << "- Attempt " << i+1 << "/" << MAX_TRIES << ": ";
		Base::identify(Base::generate());
	}
	std::cout << std::endl;
	std::cout << "TESTING: Identifying from reference" << std::endl;
	for(int i = 0; i < MAX_TRIES; i++)
	{
		std::cout << "- Attempt " << i+1 << "/" << MAX_TRIES << ": ";
		Base::identify(*(Base::generate()));
	}
	std::cout << std::endl;
	std::cout << "TESTING: Identifying from pointer (potential for unknowns)" << std::endl;
	for(int i = 0; i < MAX_TRIES; i++)
	{
		std::cout << "- Attempt " << i+1 << "/" << MAX_TRIES << ": ";
		Base::identify(Base::generateWithUnknowns());
	}
	std::cout << std::endl;
	std::cout << "TESTING: Identifying from reference (potential for unknowns)" << std::endl;
	for(int i = 0; i < MAX_TRIES; i++)
	{
		std::cout << "- Attempt " << i+1 << "/" << MAX_TRIES << ": ";
		Base::identify(*(Base::generateWithUnknowns()));
	}	
	return 0;
}