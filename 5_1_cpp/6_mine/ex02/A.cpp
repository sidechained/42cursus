#include "A.hpp"

A::A()
{
	std::cout << "A constructor called" << std::endl;
}

A::~A()
{
	std::cout << "A destructor called" << std::endl;
}

A::A(A &orig)
{
	std::cout << "A copy-constructor called" << std::endl;
	*this = orig;
}

A&	A::operator=(A &orig)
{
	std::cout << "A operator overload called" << std::endl;	
	(void)orig;
	return(*this);
}