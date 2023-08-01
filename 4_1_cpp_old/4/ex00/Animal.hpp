#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		std::string	getType() const;
		virtual	void makeSound() const;

	protected:
		std::string type;
};

#endif