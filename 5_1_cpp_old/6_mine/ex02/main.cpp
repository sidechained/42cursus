#include <stdlib.h>
#include <time.h>
#include <typeinfo>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define MAX_TRIES 5

//randomly instanciates A, B or C and returns the instance as a Base pointer.
Base*	generate(void)
{
	std::cout << "Base generate method called" << std::endl;
	switch(rand() % 3)
	{
		case 0:
			return(new A());
		case 1:
			return(new B());
		case 2:
			return(new C());
	}
	return(NULL);
}

// displays "A", "B" or "C" according to the real type of p
void	identify_from_pointer(Base* p)
{
	A* a;
	B* b;
	C* c;
	std::cout << "identify_from_pointer function called" << std::endl;
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
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}

	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}

	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}		
}

int main()
{
	std::cout << std::endl;
	std::cout << "TESTING: Identifying from pointer" << std::endl;

	int i;
	i = 0;
	while(i < MAX_TRIES)
	{
		Base	*base;
		std::cout << std::endl << "- Attempt " << i+1 << "/" << MAX_TRIES << ":" << std::endl;
		base = generate();
		identify_from_pointer(base);
		delete base;
		i++;
	}

	std::cout << std::endl;
	std::cout << "TESTING: Identifying from reference" << std::endl;

	i = 0;
	while(i < MAX_TRIES)
	{
		Base	*base;
		std::cout << std::endl << "- Attempt " << i+1 << "/" << MAX_TRIES << ":" << std::endl;
		base = generate();
		identify_from_reference(*base);
		delete base;
		i++;
	}

	return (0);
}