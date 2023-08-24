#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern &orig);
		Intern& operator=(Intern &orig);
		AForm* makeForm(std::string formName, std::string target);
};

#endif