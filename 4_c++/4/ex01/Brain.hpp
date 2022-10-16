#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

#define BRAINSIZE 4

class Brain
{
	public:
		Brain();
		~Brain();
		void	sayFirstIdea() const;
	protected:
		std::string ideas[BRAINSIZE];
};

#endif