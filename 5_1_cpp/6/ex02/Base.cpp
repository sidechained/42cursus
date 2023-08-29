#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "DFake.hpp"

Base::~Base()
{

}

void Base::setSeed(void)
{
	std::srand(static_cast<unsigned>(std::time(NULL)));
}

Base*	Base::generate(void)
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

Base*	Base::generateWithUnknowns(void)
{
	switch(rand() % 4)
	{
		case 0:
			return(new A());
		case 1:
			return(new B());
		case 2:
			return(new C());
		case 3:
			return(new DFake());
	}
	return NULL;
}

void	Base::identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "[A]" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "[B]" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "[C]" << std::endl;
	else
		std::cout << "[Not ABC]" << std::endl;		
}

void	Base::identify(Base& p)
{
	try
	{
		A& a = dynamic_cast< A& >(p);
		std::cout << "[A]";
		(void)a;
	}
	catch(const std::exception& e)
	{
		std::cout << "[Not A]";
	}

	try
	{
		B& b = dynamic_cast< B& >(p);
		std::cout << "[B]";
		(void)b;
	}
	catch(const std::exception& e)
	{
		std::cout << "[Not B]";
	}
	
	try
	{
		C& c = dynamic_cast< C& >(p);
		std::cout << "[C]";
		(void)c;
	}
	catch(const std::exception& e)
	{
		std::cout << "[Not C]";
	}

	std::cout << std::endl;
}