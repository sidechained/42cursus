/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:01:20 by grm               #+#    #+#             */
/*   Updated: 2022/09/27 07:54:40 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"



Karen::Karen()
{
	levels = {"DEBUG", "INFO", "WARNING", "ERROR"};
	func_ptrs = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
}

void Karen::debug(void)
{
	std::cout << "[DEBUG] level:" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I just love it!" << std::endl;
	std::cout << std::endl;		
}

void Karen::info(void)
{
	std::cout << "[INFO] level:" << std::endl;	
	std::cout << "I cannot believe adding extra bacon cost more money." << std::endl;
	std::cout << "You don’t put enough! If you did I would not have to ask for it!" << std::endl;
	std::cout << std::endl;	
}

void Karen::warning(void)
{
	std::cout << "[WARNING] level:" << std::endl;	
	std::cout <<  "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming here for years and you just started working here last month." << std::endl;
	std::cout << std::endl;
}

void Karen::error(void)
{
	std::cout << "[ERROR] level:" << std::endl;	
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Karen::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return (this->*func_ptrs[i])();
	}
	std::cout << "ERROR: level not found" << std::endl;
}