/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:44:55 by grm               #+#    #+#             */
/*   Updated: 2022/09/26 13:41:09 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// constructor with name
Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Constructed a Zombie named " << this->_name <<  std::endl;
}

// constructor without name
Zombie::Zombie()
{
	std::cout << "Constructed an unnamed Zombie" << this->_name <<  std::endl;
}

// destructor
Zombie::~Zombie()
{
	std::cout << "Destructed a Zombie named " << this->_name << std::endl;
}

// member function
void	Zombie::announce(void)
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

// member function
void	Zombie::setName(std::string name)
{
	this->_name = name;
	std::cout << "Gave an unnamed zombie the name " << this->_name << std::endl;
}