#ifndef WARLOCK_HPP
# define WARLOCK_HPP
# include <iostream>

class Warlock
{
	public:
		Warlock(std::string in_name, std::string in_title);
		virtual ~Warlock();
		const std::string getName() const;
		const std::string getTitle() const;
		void setTitle(const std::string in_title);
		void introduce() const;
	private:
		std::string name;
		std::string title;
		Warlock();
		Warlock(const Warlock &obj_to_copy);
		Warlock &operator=(const Warlock &obj_to_copy);
};

#endif