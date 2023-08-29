#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <stdlib.h>
# include <ctime>

class Base
{
	public:
		virtual ~Base();
		static void setSeed(void);
		static Base* generate(void);
		static Base* generateWithUnknowns(void);
		static void identify(Base* p);
		static void identify(Base& p);
};

#endif