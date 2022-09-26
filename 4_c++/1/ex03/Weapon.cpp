/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:09:21 by grm               #+#    #+#             */
/*   Updated: 2022/09/26 15:27:24 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	// check how others implemented this
}

Weapon::Weapon(std::string type)
{
	this->setType(type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string	Weapon::getType()
{
	return(this->_type);
}