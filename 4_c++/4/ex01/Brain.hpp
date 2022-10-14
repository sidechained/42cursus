#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		~Brain();
		void	sayFirstIdea() const;
	protected:
		std::string ideas[3];
};

#endif