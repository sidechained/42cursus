#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

// use of public here means that
// - the public members of the base class will remain public in the derived class
// - the protected members will remain protected
// - and the private members will remain inaccessible.
class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		void makeSound() const;
};

#endif