#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <map>
# include "ASpell.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;
		std::map < std::string, ASpell * > spellbook;
		Warlock(Warlock &obj);
		Warlock &operator=(Warlock &obj);
		
	public:
		Warlock(std::string n, std::string t);
		~Warlock();
		const std::string getName() const;
		const std::string getTitle() const;
		void setTitle(const std::string title_);
		void introduce() const;
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, ATarget &target);
};

#endif
