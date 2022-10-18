#ifndef C_HPP
# define C_HPP

#include "Base.hpp"

class C : public Base
{
	public:
		C();
		~C();
		C(C &orig);
		C& operator=(C &orig);
};

#endif