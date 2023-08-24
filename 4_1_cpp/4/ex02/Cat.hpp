#ifndef CAT_HPP
# define CAT_HPP

#include "AnimalP.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat (const Cat &old_obj);
		Cat &operator=(const Cat &t);
		void	makeSound() const;
	private:
		const Brain* brain;
};

#endif