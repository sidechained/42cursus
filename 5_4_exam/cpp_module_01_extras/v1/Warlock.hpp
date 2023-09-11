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

		Warlock();
		Warlock(const Warlock &obj_to_copy);
		Warlock &operator=(const Warlock &obj_to_copy);
	public:
		Warlock(std::string in_name, std::string in_title);
		~Warlock();
		const std::string getName() const;
		const std::string getTitle() const;
		void setTitle(const std::string in_title);
		void introduce() const;
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string spell_to_forget);
		void launchSpell(std::string spell_to_launch, ATarget &target);
};

#endif