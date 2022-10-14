#include "Brain.hpp"

Brain::Brain()
{
	ideas[0] = "one";
	ideas[1] = "two";
	ideas[2] = "three";		
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::sayFirstIdea() const
{
	std::cout << "First idea is: " << ideas[0] << std::endl;
}