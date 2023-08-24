#include <stdlib.h>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define MAX_TRIES 5

//randomly instanciates A, B or C and returns the instance as a Base pointer.
Base*	generate(void)
{
	switch(rand() % 3)
	{
		case 0:
			return(new A());
		case 1:
			return(new B());
		case 2:
			return(new C());
	}
	return NULL;
}

// displays "A", "B" or "C" according to the real type of p
void	identify_from_pointer(Base* p)
{
	A* a;
	B* b;
	C* c;
	if ((a = dynamic_cast<A *>(p)))
		std::cout << "A" << std::endl;
	if ((b = dynamic_cast<B *>(p)))
		std::cout << "B" << std::endl;
	if ((c = dynamic_cast<C *>(p)))
		std::cout << "C" << std::endl;
}

// displays "A", "B" or "C" according to the real type of p
void	identify_from_reference(Base& p)
{
	identify_from_pointer(&p);
}

int main()
{
	std::srand(static_cast<unsigned>(std::time(NULL))); 
	std::cout << std::endl;
	std::cout << "TESTING: Identifying from pointer" << std::endl;
	for(int i = 0; i < MAX_TRIES; i++)
	{
		Base *base;
		std::cout << "- Attempt " << i+1 << "/" << MAX_TRIES << ": ";
		base = generate();
		identify_from_pointer(base);
		delete base;
	}
	std::cout << std::endl;
	std::cout << "TESTING: Identifying from reference" << std::endl;
	for(int i = 0; i < MAX_TRIES; i++)
	{
		Base *base;
		std::cout << "- Attempt " << i+1 << "/" << MAX_TRIES << ": ";
		base = generate();
		identify_from_reference(*base);
		delete base;
	}
	return (0);
}