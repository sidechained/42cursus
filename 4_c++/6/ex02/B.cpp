#include "B.hpp"

B::B()
{
	std::cout << "B constructor called" << std::endl;
}

B::~B()
{
	std::cout << "B destructor called" << std::endl;
}

B::B(B &orig)
{
	std::cout << "B copy-constructor called" << std::endl;
	*this = orig;
}

B&	B::operator=(B &orig)
{
	std::cout << "B operator overload called" << std::endl;	
	(void)orig;
	return(*this);
}