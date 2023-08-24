// clear; c++ -Wall -Wextra -Werror -std=c++98 warlock.cpp main.cpp

#include "warlock.hpp"

// Q: must we write the code for the copy constructor and assignment operator even though they are private?

int main()
{
	// Warlock bob;                            //Does not compile
	// Warlock bob("Bob", "the magnificent");  //Compiles
	// Warlock jim("Jim", "the nauseating");   //Compiles
	// bob = jim;                              //Does not compile
	// Warlock jack(jim);                      //Does not compile

	Warlock const richard("Richard", "Mistress of Magma");
	richard.introduce();
	std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

	Warlock* jack = new Warlock("Jack", "the Long");
	jack->introduce();
	jack->setTitle("the Mighty");
	jack->introduce();

	delete jack;

	return (0);
}