#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

# include "SpellBook.hpp"
# include "ASpell.hpp"
# include "ATarget.hpp"

class Warlock
{
	private:
		SpellBook book;
		std::string name;
		std::string title;
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
