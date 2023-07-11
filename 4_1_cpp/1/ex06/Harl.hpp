#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {
	private:
		std::string complaintLevels[4];
		void debug();
		void info();
		void warning();
		void error();
	public:
		Harl();
		void complain(std::string level);
};

#endif