#ifndef DOG_HPP
# define DOG_HPP

#include "AnimalP.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog (const Dog &old_obj);
		Dog &operator=(const Dog &t);
		void	makeSound() const;
		const Brain* brain; // or private?
};

#endif