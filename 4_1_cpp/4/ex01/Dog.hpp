#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog (const Dog &objToCopy);
		Dog &operator=(const Dog &objToCopy);
		void makeSound() const;
	private:		
		const Brain* brain;
};

#endif