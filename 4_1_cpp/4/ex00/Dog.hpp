#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

// use of public here means that
// - the public members of the base class will remain public in the derived class
// - the protected members will remain protected
// - and the private members will remain inaccessible.
class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		void makeSound() const;
};

#endif