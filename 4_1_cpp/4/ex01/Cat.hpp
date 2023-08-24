#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat (const Cat &objToCopy);
		Cat &operator=(Cat &objToCopy);
		void makeSound() const;
		const Brain* getBrain() const;
	private:
    	const Brain* brain;
};

#endif