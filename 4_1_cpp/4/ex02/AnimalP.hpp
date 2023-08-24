#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal (const Animal &old_obj);
		Animal &operator=(const Animal &t);		
		virtual	void makeSound() const = 0;
		std::string	getType() const;

	protected:
		std::string type;
};

#endif