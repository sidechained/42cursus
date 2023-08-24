#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		// the use of const below indicates that these functions do not modify the state of the Animal object
		Animal();
		virtual ~Animal(); // enable polymorphism: destructor of the most derived class will be called
		std::string	getType() const;
		virtual	void makeSound() const; // enable polymorphism - cat calls makeSound for cat, dog calls makeSound for dog
	protected: // can be accessed by a derived class, but not by code outside of the class hierarchy
		std::string type;
};

#endif