/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:44:55 by grm               #+#    #+#             */
/*   Updated: 2022/09/26 12:25:09 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// constructor
Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Constructed a Zombie named " << this->_name <<  std::endl;
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