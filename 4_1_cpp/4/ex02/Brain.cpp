#include "Brain.hpp"

Brain::Brain()
{
	for(int i = 0; i < BRAINSIZE; i++)
	{
		// create corresponding char from '!' to '~' in ascii table (93 chars)
		// repeat three times to make the string
		char c;
		std::string s;
		c = (i % 93) + '!';
		ideas[i] += c;
		ideas[i] += c;
		ideas[i] += c;
	}
	std::cout << "Brain constructor called...";
}

Brain::Brain (const Brain &objToCopy)
{
	std::cout << "Brain copy-constructor called...";
	*this = objToCopy;
}

Brain	&Brain::operator=(const Brain &objToCopy)
{
	std::cout << "Brain assignment-operator called...";
	for (int i = 0; i < 100; i++) {
        ideas[i] = objToCopy.ideas[i];
    }
	return (*this);	
}

Brain::~Brain()
{
	std::cout << "Brain destructor called..." << std::endl;
}

void	Brain::sayFirstIdea() const
{
	std::cout << "First idea is: " << ideas[0] << std::endl;
}