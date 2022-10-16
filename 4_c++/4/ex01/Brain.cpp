#include "Brain.hpp"

Brain::Brain()
{
	int i;
	i = 0;

	while(i < BRAINSIZE)
	{
		// create corresponding char from '!' to '~' in ascii table (93 chars)
		// repeat three times to make the string
		char c;
		std::string s;
		c = (i % 93) + '!';
		ideas[i] += c;
		ideas[i] += c;
		ideas[i] += c;
		i++;
	}
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