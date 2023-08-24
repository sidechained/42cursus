#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define BRAINSIZE 100

class Brain
{
	public:
		Brain();
		~Brain();
		Brain (const Brain &old_obj);
		Brain &operator=(const Brain &t);		
		void sayFirstIdea() const;
	protected:
		std::string ideas[BRAINSIZE];
};

#endif