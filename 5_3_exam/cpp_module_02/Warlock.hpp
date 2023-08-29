#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

# include "ASpell.hpp"
# include "ATarget.hpp"
# include "SpellBook.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;
		SpellBook book;
		Warlock();
		Warlock(Warlock &);
		Warlock& operator=(Warlock &);		
	public:
		Warlock(std::string, std::string);
		~Warlock();
		std::string getName() const;
		std::string getTitle() const;
		void setTitle(const std::string);
		void introduce() const;
		void learnSpell(ASpell *);
		void forgetSpell(std::string);
		void launchSpell(std::string, ATarget &);
};

#endif
