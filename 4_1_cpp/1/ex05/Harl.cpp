#include "Harl.hpp"

Harl::Harl()
{
	complaint[0] = &Harl::debug;
	complaint[1] = &Harl::info;
	complaint[2] = &Harl::warning;
	complaint[3] = &Harl::error;

	complaintLevels[0] = "DEBUG";
	complaintLevels[1] = "INFO";
	complaintLevels[2] = "WARNING";
	complaintLevels[3] = "ERROR";
}

void Harl::debug(void)
{
	std::cout << "[DEBUG] level:" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I just love it!" << std::endl;	
}

void Harl::info(void)
{
	std::cout << "[INFO] level:" << std::endl;	
	std::cout << "I cannot believe adding extra bacon cost more money." << std::endl;
	std::cout << "You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING] level:" << std::endl;	
	std::cout << 	"I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR] level:" << std::endl;	
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == complaintLevels[i])
		{
			(this->*complaint[i])();
			return;
		}
	}
	std::cout << "ERROR: level not found" << std::endl;
}