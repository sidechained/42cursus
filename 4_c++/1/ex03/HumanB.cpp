/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:16:37 by grm               #+#    #+#             */
/*   Updated: 2022/09/26 15:35:00 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = Weapon("bare hands");
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->_weapon = weapon;
}

Weapon	HumanB::getWeapon(void)
{
	return(this->_weapon);
}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with his " << _weapon.getType() << std::endl;
}