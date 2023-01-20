#include "C.hpp"

C::C()
{
	std::cout << "C constructor called" << std::endl;
}

C::~C()
{
	std::cout << "C destructor called" << std::endl;
}

C::C(C &orig)
{
	std::cout << "C copy-constructor called" << std::endl;
	*this = orig;
}

C&	C::operator=(C &orig)
{
	std::cout << "C operator overload called" << std::endl;	
	(void)orig;
	return(*this);
}