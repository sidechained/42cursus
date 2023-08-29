#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

class Warlock
{
	private:
		std::string name;
		std::string title;
	public:
		Warlock(std::string n, std::string t);
		~Warlock();
		Warlock(Warlock &obj);
		Warlock &operator=(Warlock &obj);		
		const std::string getName() const;
		const std::string getTitle() const;
		void setTitle(const std::string title_);
		void introduce() const;
};

#endif
